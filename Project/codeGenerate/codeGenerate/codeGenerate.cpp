#include <algorithm>
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
		func->const_table.insert(pair<string, symtab_const_s*>((*iter)->ID,symtab_const));
	}

	return ss.str();
}


string codeGenerate::generate_type_part(symtab_function_block_s* func, type_part_s* type_part){
	stringstream ss;
	ss.clear(); ss.str("");

	vector<type_definition_s*>::iterator iter;
	for (iter = type_part->type_definition.end() - 1; iter != type_part->type_definition.begin() - 1; iter--){
		symtab_type_s* symtab_type = new symtab_type_s;
		if ((*iter)->type_decl->array_type_decl != NULL){
			symtab_type->array_type = new symtab_array_s;
			if ((*iter)->type_decl->array_type_decl->type_decl->simple_type_decl->SYS_TYPE == )
				symtab_type->array_type->type.type = symtab_systype_s::
			
		}
		else if ((*iter)->type_decl->record_type_decl != NULL){

		}
		else if ((*iter)->type_decl->simple_type_decl != NULL){

		}

		func->type_table.insert(pair<string, symtab_type_s*>((*iter)->ID,symtab_type));
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