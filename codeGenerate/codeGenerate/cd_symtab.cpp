#include "cd_symtab.h"

using namespace std;

symtab_type_s* symtab_function_block_s::findType(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_type_s*>::iterator iter;
		iter = current_func->type_table.find(str);
		if (iter == current_func->type_table.end()){
			continue;
		}
		return iter->second;
	}
	return NULL;
}

bool symtab_function_block_s::isType(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_type_s*>::iterator iter;
		iter = current_func->type_table.find(str);
		if (iter == current_func->type_table.end()){
			continue;
		}
		return true;
	}
	return false;
}

symtab_const_s* symtab_function_block_s::findConst(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_const_s*>::iterator iter;
		iter = current_func->const_table.find(str);
		if (iter == current_func->const_table.end()){
			continue;
		}
		return iter->second;
	}
	return NULL;
}

bool symtab_function_block_s::isConst(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_const_s*>::iterator iter;
		iter = current_func->const_table.find(str);
		if (iter == current_func->const_table.end()){
			continue;
		}
		return true;
	}
	return false;
}

symtab_function_block_s* symtab_function_block_s::findFunction(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_function_block_s*>::iterator iter;
		iter = current_func->function_table.find(str);
		if (iter == current_func->function_table.end()){
			continue;
		}
		return iter->second;
	}
	return NULL;
}

bool symtab_function_block_s::isFunction(string str){
	symtab_function_block_s* current_func;
	for (current_func = this; current_func != NULL; current_func = current_func->father_node){
		map<string, symtab_function_block_s*>::iterator iter;
		iter = current_func->function_table.find(str);
		if (iter == current_func->function_table.end()){
			continue;
		}
		return true;
	}
	return false;
}