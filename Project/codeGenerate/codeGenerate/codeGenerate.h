#pragma once
#include "cd_yacc_node.h"
#include "cd_symtab.h"
#include <sstream>
#include <fstream>

using namespace std;

class codeGenerate
{
public:
	codeGenerate();
	virtual ~codeGenerate();
	void beginGenerate(symtab_function_block_s* function_struct,program_s* program);
	void output();
private:
	string startSegment;
	string dataSegment;
	string codeSegment;
	string generateCode;

	//entry function
	string generate_program(symtab_function_block_s* function_struct, program_s* program);

	//head and body
	string generate_routine_head(symtab_function_block_s* function_struct, routine_head_s* routine_head);
	string generate_routine_body(symtab_function_block_s* function_struct, routine_body_s* routine_body);

	//head part
	string generate_const_part(symtab_function_block_s* function_struct, const_part_s* const_part);
	string generate_type_part(symtab_function_block_s* function_struct, type_part_s* type_part);
	string generate_var_part(symtab_function_block_s* function_struct, var_part_s* var_part);
	string generate_routine_part(symtab_function_block_s* function_struct, routine_part_s* routine_part);

	string generate_expression(symtab_function_block_s* function_struct, expression_s* expression);
	string generate_stmt(symtab_function_block_s* function_struct, stmt_s* stmt);
	string generate_goto(symtab_function_block_s* function_struct, goto_stmt_s* stmt);
	string generate_if(symtab_function_block_s* function_struct, if_stmt_s* if_stmt);
	string generate_while(symtab_function_block_s* function_struct, while_stmt_s* while_stmt);
	string generate_for(symtab_function_block_s* function_struct, for_stmt_s* for_stmt);
	string generate_assign(symtab_function_block_s* function_struct, assign_stmt_s* assign_stmt);
	string generate_case(symtab_function_block_s* function_struct, case_stmt_s* case_stmt);
	string generate_repeat(symtab_function_block_s* function_struct, repeat_stmt_s* repeat_stmt);
	string generate_compound_stmt(symtab_function_block_s* function_struct, compound_stmt_s* compound_stmt);
	string generate_proc(symtab_function_block_s* function_struct, proc_stmt_s* proc_stmt);
};