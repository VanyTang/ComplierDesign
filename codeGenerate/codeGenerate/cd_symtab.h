#ifndef CD_SYMTAB_H
#define CD_SYMTAB_H

#include "cd_yacc_node.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

struct symtab_systype_s{
	enum {
		INTEGER, CHAR, REAL, BOOLEAN, STRING
	}type;
};

struct symtab_range_s{
	union{
		int int_down;
		char char_down;
	} down;
	union{
		int int_up;
		char char_up;
	} up;
	enum {
		INTEGER, CHAR
	}type;
};

struct symtab_enum_s{
	map<string, int> enum_name_table;			//record the corresponding name and int
	int down;
	int up;						
};

struct symtab_array_s{
	symtab_systype_s type;
	symtab_enum_s* index_enum;
	symtab_range_s* index_range;
	int index_type;
	//0		int
	//1		char
	//2		enum
};

struct symtab_record_s{
	int size;	//basical unit is byte
	map<string, symtab_systype_s*> component;		//record the component of the 
};

struct symtab_type_s{
	symtab_record_s* record_type;
	symtab_enum_s* enum_type;
	symtab_systype_s* system_type;
	symtab_array_s* array_type;
	symtab_range_s* range_type;
	int type;
	//	0		system type such as integer and char
	//	1		array
	//	2		record
	//	3		enumerated
	//	4		range_type
};	

struct symtab_variable_s{
	int size;				// byte is the basical unit
	symtab_type_s type;		//record the variable type
	int offset;				//offset
};

struct symtab_const_s{
	union{
		int int_value;
		char char_value;
		double real_value;
		bool bool_value;
		//²»¼Óstring
	} value;
	symtab_systype_s const_type;
};


struct symtab_function_block_s{
	string name;
	symtab_type_s* return_type;
	symtab_function_block_s* father_node;
	map<string, symtab_variable_s*> variable_table;
	map<string, symtab_const_s*> const_table;
	map<string, symtab_type_s*> type_table;
	map<string, symtab_function_block_s*> function_table;

	//interface
	symtab_type_s* findType(string);
	bool isType(string);
	symtab_const_s* findConst(string);
	bool isConst(string);
	symtab_variable_s* findVariable(string);
	bool isVariable(string);
	symtab_function_block_s* findFunction(string);
	bool isFunction(string);

};

#endif