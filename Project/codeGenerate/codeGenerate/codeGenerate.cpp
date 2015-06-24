#include <algorithm>
#include <iostream>
#include <fstream>
#include "codeGenerate.h"

using namespace std;

codeGenerate::codeGenerate(){
	
}

codeGenerate::~codeGenerate(){

}

void codeGenerate::beginGenerate(symtab_function_block_s* func, program_s* program){
	generateCode = generate_program(func, program);
	output();
}

void codeGenerate::output(){
	ofstream fout("output.asm");
	fout << generateCode;
	fout.close();
}

void codeGenerate::exit_with_error(string error){
	cout << "compile error: " << error << endl;
	system("pause");
	exit(1);
}

string codeGenerate::generate_program(symtab_function_block_s* func, program_s* program){
	stringstream ss;
	ss.clear();
	ss.str("");
	
	//此处可能待添加修改
	ss << generate_routine_head(func, program->routine->routine_head);
	ss << generate_routine_body(func, program->routine->routine_body);

	return ss.str();
}

string codeGenerate::generate_routine_head(symtab_function_block_s* func, routine_head_s* routine_head){
	stringstream ss;
	ss.clear();
	ss.str("");

	if (routine_head->const_part != NULL){
		ss << generate_const_part(func, routine_head->const_part);
	}
	if (routine_head->type_part != NULL){
		ss << generate_type_part(func, routine_head->type_part);
	}
	if (routine_head->var_part != NULL){
		ss << generate_var_part(func, routine_head->var_part);
	}
	if (routine_head->routine_part != NULL){
		ss << generate_routine_part(func, routine_head->routine_part);
	}

	return ss.str();
}

string codeGenerate::generate_const_part(symtab_function_block_s* func, const_part_s* const_part){
	stringstream tmp;
	stringstream ss;
	ss.clear();
	ss.str("");

	vector<const_expr_list_s*>::iterator iter;
	for (iter = const_part->const_expr_list.end() - 1; iter != const_part->const_expr_list.begin() - 1; iter--){
		symtab_const_s* symtab_const = new symtab_const_s;
		if ((*iter)->const_value->TYPE == 0){
			tmp.clear(); tmp.str("");
			symtab_const->const_type.type = symtab_systype_s::INTEGER;
			tmp << (*iter)->const_value->VALUE;
			tmp >> symtab_const->value.int_value;
		}
		else if ((*iter)->const_value->TYPE == 1){
			tmp.clear(); tmp.str("");
			symtab_const->const_type.type = symtab_systype_s::REAL;
			tmp << (*iter)->const_value->VALUE;
			tmp >> symtab_const->value.char_value;
		}
		else if ((*iter)->const_value->TYPE == 2){
			tmp.clear(); tmp.str("");
			symtab_const->const_type.type = symtab_systype_s::CHAR;
			tmp << (*iter)->const_value->VALUE;
			tmp >> symtab_const->value.real_value;
		}
		else if ((*iter)->const_value->TYPE == 3){

			//如果是字符串这里待添加修改
		}
		else if ((*iter)->const_value->TYPE == 4){
			tmp.clear(); tmp.str("");
			symtab_const->const_type.type = symtab_systype_s::BOOLEAN;
			tmp << (*iter)->const_value->VALUE;
			tmp >> symtab_const->value.bool_value;
		}
		if ((func->const_table).insert(make_pair((*iter)->ID, symtab_const)).second == false){
			stringstream err; err.clear(); err.str("");
			err << "Duplicated IDs have been declared in the const part:" << (*iter)->ID;
			exit_with_error(err.str());
		}
	}

	return ss.str();
}


string codeGenerate::generate_type_part(symtab_function_block_s* func, type_part_s* type_part){
	stringstream ss;
	ss.clear(); ss.str("");

	vector<type_definition_s*>::iterator iter;
	for (iter = type_part->type_definition.end() - 1; iter != type_part->type_definition.begin() - 1; iter--){
		symtab_type_s* symtab_type = new symtab_type_s;
		//array类型
		if ((*iter)->type_decl->array_type_decl != NULL){
			symtab_type->array_type = new symtab_array_s;
			symtab_type->enum_type = NULL;
			symtab_type->record_type = NULL;
			symtab_type->system_type = NULL;
			symtab_type->range_type = NULL;
			symtab_type->type = 1;	//array type
			//assign the array type
			if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE_NAME == "INTEGER"){
				symtab_type->array_type->type.type = symtab_systype_s::INTEGER;
			}
			else if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE_NAME == "CHAR"){
				symtab_type->array_type->type.type = symtab_systype_s::CHAR;
			}
			else if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE_NAME == "REAL"){
				symtab_type->array_type->type.type = symtab_systype_s::REAL;
			}
			else if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE_NAME == "BOOLEAN"){
				symtab_type->array_type->type.type = symtab_systype_s::BOOLEAN;
			}
			else if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE_NAME == "STRING"){
				symtab_type->array_type->type.type = symtab_systype_s::STRING;
			}
			//index type
			if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->TYPE == simple_type_decl_s::RANGE_TYPE){
				symtab_type->array_type->index_type 
					= (*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->isChar;
				if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MAX <=
					(*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MIN){
					stringstream err; err.clear(); err.str("");
					err << "Range is not allowed from bigger one to smaller one:" << (*iter)->ID;
					exit_with_error(err.str());
				}
				if (symtab_type->array_type->index_type == 0){
					symtab_type->array_type->index_range->type = symtab_range_s::INTEGER;
					symtab_type->array_type->index_range->up.int_up
						= (*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MAX;
					symtab_type->array_type->index_range->down.int_down
						= (*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MIN;
				}
				else if (symtab_type->array_type->index_type == 1){
					symtab_type->array_type->index_range->type = symtab_range_s::CHAR;
					symtab_type->array_type->index_range->up.char_up
						= (char)((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MAX);
					symtab_type->array_type->index_range->down.char_down
						= (char)((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->MIN);
				}
				else{
					stringstream err; err.clear(); err.str("");
					err << "Array declaration is wrong because of the array index expression:" << (*iter)->ID;
					exit_with_error(err.str());
				}
			}
			else if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->TYPE == simple_type_decl_s::ID_TYPE){
				vector<string>::iterator idIter;
				for (idIter = (*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->ID.end() - 1;
					idIter != (*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->ID.begin() - 1; idIter--){
					if (func->type_table.find(*idIter)->second->enum_type == NULL){
						stringstream err;
						err.clear(); err.str("");
						err << (*idIter) << "is not a enum type";
						exit_with_error(err.str());
					}
					symtab_type->array_type->index_enum = func->type_table.find(*idIter)->second->enum_type;
				}
			}
			//index error
			else{
				stringstream err; err.clear(); err.str("");
				err << "this index expression type of array declaration is not supported:" << (*iter)->ID;
				exit_with_error(err.str());
			}
		}
		//record 类型
		else if ((*iter)->type_decl->record_type_decl != NULL){
			symtab_type->type = 2;
			symtab_type->record_type = new symtab_record_s;
			symtab_type->array_type == NULL;
			symtab_type->enum_type == NULL;
			symtab_type->range_type == NULL;
			symtab_type->system_type == NULL;
			symtab_type->record_type->size = 0;
			vector<field_decl_s*>::iterator fieldIter;
			int basic_byte = 0;//record the namelist size byte
			for (fieldIter = (*iter)->type_decl->record_type_decl->field_decl.end() - 1;
				fieldIter != (*iter)->type_decl->record_type_decl->field_decl.begin() - 1; fieldIter--){
				symtab_systype_s* symtab_systype = new symtab_systype_s;
				basic_byte = 0;
				if ((*fieldIter)->type_decl->simple_type_decl == NULL){
					stringstream err; err.clear(); err.str("");
					err << "record type declaration doesn't support complicated type:" << (*iter)->ID;
					exit_with_error(err.str());
				}

				//confirm the type of the namelist
				if ((*fieldIter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "INTEGER")
				{
					symtab_systype->type = symtab_systype_s::INTEGER;
					basic_byte = 2;
				}
				else if ((*fieldIter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "CHAR"){
					symtab_systype->type = symtab_systype_s::CHAR;
					basic_byte = 1;
				}
				else if ((*fieldIter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "REAL"){
					symtab_systype->type = symtab_systype_s::REAL;
					//此处待添加和修改，浮点型处理
				}
				else if ((*fieldIter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "BOOLEAN"){
					symtab_systype->type = symtab_systype_s::BOOLEAN;
					basic_byte = 1;
				}
				else if ((*fieldIter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "SRTRING"){
					symtab_systype->type = symtab_systype_s::STRING;
					//此处待添加和修改，字符串类型处理
				}
				
				vector<string>::iterator nameIter;
				for (nameIter = (*fieldIter)->name_list.end() - 1; 
					nameIter != (*fieldIter)->name_list.begin() - 1; nameIter--){
					//insert system type
					symtab_type->record_type->component.insert(pair<string, symtab_systype_s*>((*nameIter),symtab_systype));
					//increase the size
					symtab_type->record_type->size += basic_byte;
				}
			}
		}
		//简单类型
		else if ((*iter)->type_decl->simple_type_decl != NULL){
			//系统类型（5种）
			if ((*iter)->type_decl->simple_type_decl->TYPE == simple_type_decl_s::SYS_TYPE){
				symtab_type->type = 0; //system type;
				symtab_type->system_type = new symtab_systype_s;
				symtab_type->array_type = NULL;
				symtab_type->enum_type = NULL;
				symtab_type->range_type = NULL;
				symtab_type->record_type = NULL;
				if ((*iter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "INTEGER"){
					symtab_type->system_type->type = symtab_systype_s::INTEGER;
				}
				else if ((*iter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "BOOLEAN"){
					symtab_type->system_type->type = symtab_systype_s::BOOLEAN;
				}
				else if ((*iter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "REAL"){
					symtab_type->system_type->type = symtab_systype_s::REAL;
				}
				else if ((*iter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "CHAR"){
					symtab_type->system_type->type = symtab_systype_s::CHAR;
				}
				else if ((*iter)->type_decl->simple_type_decl->SYS_TYPE_NAME == "STRING"){
					symtab_type->system_type->type = symtab_systype_s::STRING;
				}
			}
			//范围类型
			else if ((*iter)->type_decl->simple_type_decl->TYPE == simple_type_decl_s::RANGE_TYPE){
				symtab_type->type = 4; //range type;
				symtab_type->range_type = new symtab_range_s;
				symtab_type->system_type = NULL;
				symtab_type->array_type = NULL;
				symtab_type->enum_type = NULL;
				symtab_type->record_type = NULL;

				if ((*iter)->type_decl->simple_type_decl->isChar == 0){ // int
					symtab_type->range_type->type = symtab_range_s::INTEGER;
					if ((*iter)->type_decl->simple_type_decl->MIN >= (*iter)->type_decl->simple_type_decl->MAX){
						stringstream err; err.clear(); err.str("");
						err << "Range is not allowed from bigger one to smaller one:" << (*iter)->ID;
						exit_with_error(err.str());
					}
					symtab_type->range_type->down.int_down = (*iter)->type_decl->simple_type_decl->MIN;
					symtab_type->range_type->up.int_up = (*iter)->type_decl->simple_type_decl->MAX;
				}
				else if ((*iter)->type_decl->simple_type_decl->isChar == 1){ //char
					symtab_type->range_type->type = symtab_range_s::CHAR;
					if ((*iter)->type_decl->simple_type_decl->MIN >= (*iter)->type_decl->simple_type_decl->MAX){
						stringstream err; err.clear(); err.str("");
						err << "Range is not allowed from bigger one to smaller one:" << (*iter)->ID;
						exit_with_error(err.str());
					}
					symtab_type->range_type->down.char_down = (char)(*iter)->type_decl->simple_type_decl->MIN;
					symtab_type->range_type->up.char_up = (char)(*iter)->type_decl->simple_type_decl->MAX;
				}
			}
			//枚举类型
			else if ((*iter)->type_decl->simple_type_decl->TYPE == simple_type_decl_s::ENUM_TYPE){
				symtab_type->type = 3;//enum type
				symtab_type->enum_type = new symtab_enum_s;
				symtab_type->range_type = NULL;
				symtab_type->system_type = NULL;
				symtab_type->array_type = NULL;
				symtab_type->record_type = NULL;
				vector<string>::iterator nameIter;
				int size = 0;
				symtab_type->enum_type->down = MIN_ENUM_INT;
				for (nameIter = (*iter)->type_decl->simple_type_decl->ID.end() - 1;
					nameIter != (*iter)->type_decl->simple_type_decl->ID.begin() - 1; nameIter--){
					symtab_type->enum_type->enum_name_table.insert(make_pair((*nameIter),size++));
				}
				symtab_type->enum_type->up = size - 1;
				if (symtab_type->enum_type->up < symtab_type->enum_type->down){
					stringstream err; err.clear(); err.str("");
					err << "Enum type must has at least one parameter: " << (*iter)->ID;
					exit_with_error(err.str());
				}
			}
			//已命名ID类型
			else if ((*iter)->type_decl->simple_type_decl->TYPE == simple_type_decl_s::ID_TYPE){
				vector<string>::iterator idIter;
				for (idIter = (*iter)->type_decl->simple_type_decl->ID.end() - 1;
					idIter != (*iter)->type_decl->simple_type_decl->ID.begin() - 1; idIter--){
					map<string, symtab_type_s*>::iterator definedType;
					definedType = func->type_table.find((*idIter));
					if (definedType == func->type_table.end()){
						stringstream err; err.clear(); err.str("");
						err << "NO ID declared before you using it:" << *idIter;
						exit_with_error(err.str());
					}
				}
			}
		}

		if (func->type_table.insert(make_pair((*iter)->ID, symtab_type)).second == false){
			stringstream err; err.clear(); err.str("");
			err << "NO ID declared before you using it:" << (*iter)->ID;
			exit_with_error(err.str());
		}
	}
}


//---------------------------------------------------------------------------------------------
//---------------------------------------华丽丽的分割线----------------------------------------
//---------------------------------------------------------------------------------------------

string codeGenerate::generate_routine_body(symtab_function_block_s* func, routine_body_s* routine_body){

}

string codeGenerate::generate_expression(symtab_function_block_s* func, expression_s* expression){
     
}

string codeGenerate::generate_if(symtab_function_block_s* func, if_stmt_s* if_stmt){
	
}

string codeGenerate::generate_while(symtab_function_block_s* func,while_stmt_s* while_stmt_s){

}

string codeGenerate::generate_for(symtab_function_block_s* func, for_stmt_s* for_stmt_s){

}

string codeGenerate::generate_repeat(symtab_function_block_s* func, repeat_stmt_s* repeat_stmt){

}

string codeGenerate::generate_assign(symtab_function_block_s* func, assign_stmt_s* assign_stmt){

}

string codeGenerate::generate_goto(symtab_function_block_s* func, goto_stmt_s* goto_stmt){
	stringstream ss;
	ss.clear();
	ss.str("");
	ss << "LABEL" << goto_stmt->INTEGER << '\n';
	return ss.str();
}

string codeGenerate::generate_case(symtab_function_block_s* func, case_stmt_s* case_stmt){
	stringstream ss;
	ss.clear();
	ss.str("");
	//此处待添加

	return ss.str();
}

string codeGenerate::generate_stmt(symtab_function_block_s* func, stmt_s* stmt){
	stringstream ss;
	ss.clear();
	ss.str("");
	if (stmt->INTEGER != NULL){
		ss << "LABLE" << *(stmt->INTEGER) << ":\n";
	}
	if (stmt->non_label_stmt->assign_stmt != NULL){
		ss << generate_assign(func, stmt->non_label_stmt->assign_stmt);
	}
	else if (stmt->non_label_stmt->case_stmt != NULL){
		ss << generate_case(func, stmt->non_label_stmt->case_stmt);
	}
	else if (stmt->non_label_stmt->compound_stmt != NULL){
		ss << generate_compound_stmt(func, stmt->non_label_stmt->compound_stmt);
	}
	else if (stmt->non_label_stmt->for_stmt != NULL){
		ss << generate_for(func, stmt->non_label_stmt->for_stmt);
	}
	else if (stmt->non_label_stmt->while_stmt != NULL){
		ss << generate_while(func, stmt->non_label_stmt->while_stmt);
	}
	else if (stmt->non_label_stmt->repeat_stmt != NULL){
		ss << generate_repeat(func, stmt->non_label_stmt->repeat_stmt);
	}
	else if (stmt->non_label_stmt->goto_stmt != NULL){
		ss << generate_goto(func, stmt->non_label_stmt->goto_stmt);
	}
	else if (stmt->non_label_stmt->proc_stmt != NULL){
		ss << generate_proc(func, stmt->non_label_stmt->proc_stmt);
	}
	else if (stmt->non_label_stmt->if_stmt != NULL){
		ss << generate_if(func, stmt->non_label_stmt->if_stmt);
	}

	return ss.str();
}