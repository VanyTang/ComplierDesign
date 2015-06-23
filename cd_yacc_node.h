#ifndef	CD_YACC_NODE
#define	CD_YACC_NODE

#include <string>
#include <vector>

using namespace std;

struct routine_s;
struct routine_head_s;
struct routine_body_s;
struct type_definition_s;
struct type_decl_s;
struct simple_type_decl_s;
struct array_type_decl_s;
struct record_type_decl_s;
struct const_part_s;
struct var_part_s;
struct type_part_s;
struct routine_part_s;
struct function_decl_s;
struct function_head_s;
struct procedure_decl_s;
struct procedure_head_s;
struct const_expr_list_s;
struct const_value_s;
struct field_decl_s;
struct var_decl_s;
struct function_head_s;
struct parameters_s;
struct para_type_list_s;
struct compound_stmt_s;
struct var_para_list_s;
struct val_para_list_s;
struct stmt_s;
struct assign_stmt_s;
struct non_label_stmt_s;
struct proc_stmt_s;
struct if_stmt_s;
struct repeat_stmt_s;
struct while_stmt_s;
struct for_stmt_s;
struct case_stmt_s;
struct goto_stmt_s;
struct expression_s;
struct args_list_s;
struct else_clause_s;
struct direction_s;
struct case_expr_s;
struct expr_s;
struct term_s;
struct factor_s;
struct para_decl_list_s;

//program: program_head routine .
struct program_s
{
	string ID;											//the ID in program_head
	routine_s *routine;
};
//program_head: PROGRAM ID;
struct program_head_s
{
	string ID;											//record the program labels;
};

//routine ： routine_head  routine_body
struct routine_s{
	routine_head_s* routine_head;
	routine_body_s* routine_body;
};

//routine_head ： const_part  type_part  var_part  routine_part
struct routine_head_s{
	const_part_s* const_part;							//const declare statement
	var_part_s* var_part;								//variable declare statement
	type_part_s* type_part;								//type define statement
	routine_part_s* routine_part;						//routine part statement
	vector<function_decl_s*> fucntion_decl;				//record the function declaration
	vector<procedure_decl_s*> procedure_decl;			//record the procedure declaration
};

//const_part ： CONST  const_expr_list  |  ε
struct const_part_s{
	vector<const_expr_list_s*> const_expr_list;	//record all the const expr_list
};

//const_expr_list ： const_expr_list  ID  EQUAL  const_value  SEMI |  ID  EQUAL  const_value  SEMI
struct const_expr_list_s{
	const_value_s* const_value;							//the value of corresponding ID
	string ID;											//record the const ID which is corresponding to const value
	const_expr_list_s* next;							//record the next const_expr_list
};

//const_value ： INTEGER  |  REAL  |  CHAR  |  STRING  |  SYS_CON
struct const_value_s{
	string VALUE;										//record the value of the const
	enum TYPE{											//record the type of the const value
		INTEGER = 0,
		REAL = 1,
		CHAR = 2,
		STRING = 3,
	 	SYS_CON = 4
	} TYPE;
};

//type_part ： TYPE type_decl_list  |  ε
struct type_part_s{
	vector<type_definition_s*> type_definition;			//record a lot of type definitions	
};

//type_decl_list ： type_decl_list  type_definition  |  type_definition
struct type_decl_list_s{
	type_decl_list_s* next;
	type_definition_s* type_definition;
};

//type_definition ： ID  EQUAL  type_decl  SEMI
struct type_definition_s{
	string ID;											//record the identifier of the type definition
	type_decl_s* type_decl;								//record the type declaration
};

//type_decl ： simple_type_decl  |  array_type_decl  |  record_type_decl
struct type_decl_s{
	simple_type_decl_s* simple_type_decl;				//simple type declaration
	array_type_decl_s* array_type_decl;					//array type declaration
	record_type_decl_s* record_type_decl;				//record type declaration
};
 
/*simple_type_decl ： SYS_TYPE  |  ID  |  LP  name_list  RP  
                |  const_value  DOTDOT  const_value  
                |  MINUS  const_value  DOTDOT  const_value
                |  MINUS  const_value  DOTDOT  MINUS  const_value
                |  ID  DOTDOT  ID*/
struct simple_type_decl_s{
	int MIN;											//record the minimum number of a range type
	int MAX;											//record the maximum number of a range type
	vector<string> ID;									//record the identiiers of types which are declared before
	string SYS_TYPE_NAME;
	// enum {												//record the system types which are showed as following 
	// 	INTEGER = 0;
	// 	REAL = 1;
	// 	CHAR = 2;
	// 	STRING = 3;
	// } SYS_TYPE;
	enum {												//record the type of the delaration
		SYS_TYPE = 0,
		ID_TYPE = 1,
		ENUM_TYPE = 2,
		RANGE_TYPE = 3
	} TYPE;
};

//array_type_decl ： ARRAY  LB  simple_type_decl  RB  OF  type_decl
struct array_type_decl_s{
	simple_type_decl_s* simple_type_decl;				//record the simple type declaration
	type_decl_s* type_decl;								//record the type declaration of array
};

//record_type_decl ： RECORD  field_decl_list  END
struct record_type_decl_s{
	vector<field_decl_s*> field_decl;					//record all the field_decl_list
};

//field_decl_list ： field_decl_list  field_decl  |  field_decl
struct field_decl_list_s{
	field_decl_list_s* next;							//record the next field declaration
	field_decl_s* field_decl;							//record the current field declaration
};

//field_decl ： name_list  COLON  type_decl  SEMI
struct field_decl_s{
	vector<string> name_list;							//record all the ID into name_liat
	type_decl_s* type_decl;								//record the corresponding type
};

//name_list ： name_list  COMMA  ID  |  ID
struct name_list_s{
	name_list_s* next;									//record the next name or ID
	string ID;											//record each ID into each struct
};

//var_part ： VAR  var_decl_list  |  ε
struct var_part_s{
	vector<var_decl_s*> var_decl;						//record all the var declaration list of this type
};

//var_decl_list :  var_decl_list  var_decl  |  var_decl
struct var_decl_list_s{
	var_decl_list_s* next;								//record the next variable declaration of this type
	var_decl_s* var_decl;								//record the current variable declaration
};

//var_decl :  name_list  COLON  type_decl  SEMI
struct var_decl_s{
	vector<string> name_list;								//record the name list of one type
	type_decl_s* type_decl;								//record the type of the name list
};


//routine_part:  routine_part  function_decl  |  routine_part  procedure_decl |  function_decl  |  procedure_decl | e
struct routine_part_s{
	routine_part_s* next; 								//record the next routine part
	procedure_decl_s* procedure_decl;					//record the current procedure declaration
	function_decl_s* function_decl;						//record the current function declatation
};

//function_decl : function_head  SEMI  routine  SEMI
struct function_decl_s{
	function_head_s* function_head;						//record the function head of the function
	routine_s* routine;									//record the function routine
};

//function_head :  FUNCTION  ID  parameters  COLON  simple_type_decl 
struct function_head_s{
	string ID;											//record the identifier of the function
	simple_type_decl_s* simple_type_decl;				//record the type of return value
	parameters_s* parameters;							//record the parameters which are put into the function
};

//procedure_decl :  procedure_head  SEMI  routine  SEMI
struct procedure_decl_s{
	procedure_head_s* procedure_head;					//record the procedure head of the procedure
	routine_s* routine;
};

//procedure_head :  PROCEDURE ID parameters 
struct procedure_head_s{
	string ID;											//record the identifier of the procedure
	parameters_s* parameters;							//record the parameters which are put into the procedure
};

//parameters ： LP  para_decl_list  RP  |  ε
struct parameters_s{
	vector<para_type_list_s*> para_decl_list;			//record the parameters that are listed in this list
};

//para_decl_list ： para_decl_list  SEMI  para_type_list | para_type_list
struct para_decl_list_s{
	para_decl_list_s* next;								//record the next parameter declaration
	para_type_list_s* para_type_list;					//record the parameter declaration with type
};

//para_type_list ： var_para_list COLON  simpe_type_decl  |  val_para_list  COLON  simple_type_decl
struct para_type_list_s{
	var_para_list_s* var_para_list;						//record the variable parameter of the list
	val_para_list_s* val_para_list;						//record the value parameter of the list
	simple_type_decl_s* simple_type_decl;				//record the type of the parameter
};

//var_para_list ： VAR name_list
struct var_para_list_s{
	name_list_s* name_list;								//record the name list of the variable parameter
};

//val_para_list ： name_list
struct val_para_list_s{
	name_list_s* name_list;								//record the name list of the parameter value
};

//routine_body ： compound_stmt
struct routine_body_s{
	compound_stmt_s* compound_stmt;						//recrod the statement that will appear in the routine body
};

//compound_stmt ： BEGIN  stmt_list  END
struct compound_stmt_s{
	vector<stmt_s*> stmt;								//record the statement without 'begin' and 'end' 
};

//stmt_list ： stmt_list  stmt  SEMI  |  ε
struct stmt_list_s{
	stmt_list_s* next;									//record the next statement
	stmt_s* stmt;										//record the current statement
};

//stmt ： INTEGER  COLON  non_label_stmt  |  non_label_stmt
struct stmt_s{
	int* INTEGER;										//record the label of the label statement. If there is no label ,the pointer is supposed to be set NULL
	non_label_stmt_s* non_label_stmt;					//record the statement without any label
};

//non_label_stmt ： assign_stmt | proc_stmt | compound_stmt | if_stmt | repeat_stmt | while_stmt | for_stmt | case_stmt | goto_stmt
struct non_label_stmt_s{
	//if any of the statement below doesn't exist, the pointer is expected to be NULL
	assign_stmt_s* assign_stmt;							//record the assign statement
	proc_stmt_s* proc_stmt;								//record the procedure statement
	compound_stmt_s* compound_stmt;					//record the compound statement
	if_stmt_s* if_stmt;									//record the if statement
	repeat_stmt_s* repeat_stmt;							//record the repeat statement
	while_stmt_s* while_stmt;							//record the while statement
	for_stmt_s* for_stmt;								//record the for statement
	case_stmt_s* case_stmt;								//record the case statement
	goto_stmt_s* goto_stmt;								//record the goto statement
};

/*assign_stmt ： ID  ASSIGN  expression
           | ID LB expression RB ASSIGN expression
           | ID  DOT  ID  ASSIGN  expression*/
struct assign_stmt_s{
	string ID;											//record the subject identifier of the assign statement
	//if the index expression doesn't exist, the pointer  "expression_1" is expected to be NULL
	expression_s* expression_idx;						//record the index expression in the second production equation
	expression_s* expression;							//record the expression locating right of the equation
	//if the struct expression doesn't exist, the pair pointer
	pair<string,string>* ID_DOT_ID;						//record the struct subject identifier of the equation	
	int TYPE;
	//type is designed as following:
	//0			"ID" 									is expressed by ID
	//1			"ID[expression]" 						is regarded as a whole which is expressed by ID and expression_1
	//2			"ID.ID" 								is expressed by ID_DOT_ID
};

/*proc_stmt ： ID
          |  ID  LP  args_list  RP
          |  SYS_PROC
          |  SYS_PROC  LP  args_list  RP
          |  READ  LP ID RP*/
struct proc_stmt_s{
	string ID;											//record the identifier of the procedure statements which can be SYS_PROC/READ/custom procedure
	//if it's not "ID LP args_list RP" then the pointer below is NULL
	args_list_s* args_list;								//record the arguments list which is used in the statement
	//if it's not "SYS_PROC LP expression_list RP" then the pointer below is NULL
	//expression_list_s* expression_list;					//record the expression list which is used in the system procedure call
	//if it's not "READ LP factor RP" then the pointer below is NULL
	string readID;

	//factor_s* factor;									//record the factor which is used in the read procedure call
};	

//if_stmt ： IF  expression  THEN  compound_stmt  else_clause
struct if_stmt_s{
	expression_s* expression;							//record the judgement expression
	compound_stmt_s* compound_stmt;						//record the statement which will be exeucute if condition is true
	else_clause_s* else_clause;							//record the else clause
};

//else_clause ： ELSE compound_stmt |  ε
struct else_clause_s{
	compound_stmt_s* compound_stmt;						//record the else statement;
};

//repeat_stmt ： REPEAT  stmt_list  UNTIL  expression
struct repeat_stmt_s{
	//stmt_list is recursive, therefore vector is used here
	vector<stmt_s*> stmt;								//record the repeat statements which are used in the repeat statement
	expression_s* expression;							//record the expression statement of the until condition
};

//while_stmt ： WHILE  expression  DO compound_stmt
struct while_stmt_s{
	expression_s* expression;							//record the expression condition of while statement
	compound_stmt_s* compound_stmt;						//record the compound statement of while statement
};

//for_stmt ： FOR  ID  ASSIGN  expression  direction  expression  DO compound_stmt
struct for_stmt_s{
	compound_stmt_s* compound_stmt;						//record the compound statement
	string ID;											//record the identifier
	expression_s* expression1;							//record the first expresstion
	expression_s* expression2;							//record the second expression
	enum directionEnum{										//record the for statement variable direction
		TO = 0,
		DOWNTO = 1
	}direction; //direction ： TO | DOWNTO
};

struct direction_s
{
    int dir; //TO:0, DOWNTO:1
};

//case_stmt ： CASE expression OF case_expr_list  END
struct case_stmt_s{
	expression_s* expression;							//record the expression of the case statement
	vector<case_expr_s*> case_expr;						//record the case expression list
};

//case_expr_list ： case_expr_list  case_expr  |  case_expr
struct case_expr_list_s{
	case_expr_list_s* next;								//record the next case expression
	case_expr_s* case_expr;								//record the current case expression
};

//case_expr ： const_value  COLON  stmt  SEMI |  ID  COLON  stmt  SEMI
struct case_expr_s{
	//if const value is not preferred, it will be saved as NULL
	const_value_s* const_value;							//record the const value of this type 
	//if ID doesn't exist, it will be saved as NULL too
	string* ID;											//record the identifier
	stmt_s* stmt;										//record the statement of the case expresstion 
};

//goto_stmt ： GOTO  INTEGER
struct goto_stmt_s{
	int INTEGER;										//record the label value
};

//expression_list ： expression_list  COMMA  expression  |  expression
//struct expression_list_s{
//	expression_list_s* next;							//record the next expression
//	expression_s* expression;							//record the current expression
//};

	/*expression ： expression  GE  expr  |  expression  GT  expr  |  expression  LE  expr
	          |  expression  LT  expr  |  expression  EQUAL  expr  |  expression  UNEQUAL  expr  |  expr*/
struct expression_s{
	expression_s* next;									//record the next expr
	expr_s* expr;										//record the current expr
	enum TYPE{											//record the comparator on expr
		GE = 0,											//0		A >= B
		GT = 1,											//1		A > B
		LE = 2,											//2		A <= B
		LT = 3,											//3		A < B
		EQUAL = 4,										//4		A == B
		UNEQUAL = 5,									//5		A != B
		NULL_OPERATOR = 6								//6		A
	}TYPE;
};

//expr ： expr  PLUS  term  |  expr  MINUS  term  |  expr  OR  term  |  term
struct expr_s{
	expr_s* next;										//record the next term
	term_s* term;										//record the current term
	enum TYPE{											//record the logical operator on term
		PLUS = 0,										//0		A + B
		MINUS = 1,										//1		A - B
		OR = 2,											//2		A || B
		NULL_OPERATOR = 3								//3 	A
	}TYPE;										
};

//term ： term  MUL  factor  |  term  DIV  factor  |  term  MOD  factor |  term  AND  factor  |  factor
struct term_s{
	factor_s* factor;									//record the current factor
	term_s* next;										//record the next factor
	enum TYPE{
		MUL = 0,										//0		A * B
		DIV = 1,										//1		A / B
		MOD = 2,										//2		A % B
		AND = 3,										//3		A && B
		NULL_OPERATOR = 4								//4		A
	}TYPE;
};

/*factor ： ID  |  ID  LP  args_list  RP  |  SYS_FUNCT | SYS_FUNCT  LP  args_list  RP  |  const_value  |  LP  expression  RP
          |  NOT  factor  |  MINUS  factor  |  ID  LB  expression  RB |  ID  DOT  ID*/
struct factor_s{
	string ID;
	args_list_s* args_list;							//record the ID(args_list) where ID is a function ID
	//args_list_s* args_list2;							//record the SYS_FUNCT(args_list)
	const_value_s* const_value;							//record the const value
	pair<string,string>* ID_DOT_ID;						//record the ID.ID
	expression_s* expression;							//record the expression
	//expression_s* expression2;							//record the ID[expression]
	factor_s* next;										//record the next factor in "NOT factor | MINUS factor"
	enum TYPE{
		MINUS_FACTOR = 0,
		NOT_FACTOR = 1,
		ID_TYPE = 2,
		FUNCTION_WITH_ARGS = 3,
		SYS_FUNCT = 4,
		SYS_FUNCT_WITH_ARGS = 5,
		CONST_VALUE = 6,
		EXPRESSION = 7,
		ID_WITH_EXPRESSION = 8,
		ID_DOT_ID_TYPE = 9
	}TYPE;
};

//args_list ： args_list  COMMA  expression  |  expression
struct args_list_s{
	args_list_s* next;									//record the next argument expression
	expression_s* expression;							//record the current argument expression
};

#endif
