%{
	#include "cd_yacc_node.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <iostream>
        #include <vector>
        #include <string>
        #define YYSTYPE char*
        using namespace std;


        extern int line_no;
	program_s program;

        extern "C"{
              void yyerror(const char *s);
              extern int yylex(void);
        }

        inline int str2int(const string& str)
        {
            int ret(0);
            int len(str.length());
            for(int i = 0;i < len;++i)
            {
                if('0'<=str[i]&&str[i]<='9')
                    ret += str[i]-'0';
                else
                    yyerror("invalid convertion from string to int");
                ret *= 10;
            }
            return ret/10;
        }

        inline char str2char(const string& str)
        {
            if(str.length()!=1) yyerror("invalid convertion from string to char");
            return str[0];
        }
%}

%token _LP _RP _LB _RB _DOT _COLON _COMMA _SEMI _MOD _MUL _PLUS _GE _GT _LE _LT _EQUAL _DIV _ASSIGN 
%token _SYS_FUNC _SYS_PROC _SYS_CON _SYS_TYPE  _UNEQUAL
%token _DO _TO _IF _OR _OF _END _FOR _VAR _NOT _AND _ELSE _READ _CASE _THEN _GOTO _ARRAY _BEGIN _UNTIL _WHILE
%token _CONST _REPEAT _RECORD _DOWNTO _PROGRAM _PROCEDURE _FUNCTION
%token _ID _INTEGER_NUM _REAL_NUM _CHAR_NUM _STRING_NUM _MINUS _TYPE

%%

program : program_head routine _DOT{
        //printf("program reduced.\n");
	    $$ = (char*)&program;
        ((program_s*)$$)->ID = ((program_head_s*)$1)->ID;
	    ((program_s*)$$)->routine = (routine_s*)$2;
};
program_head : _PROGRAM _ID _SEMI{
        //printf("program_head %s reduced.\n",$2);
        $$ = (char*)(new program_head_s);
        ((program_head_s*)$$)->ID = string($2);
};
routine : routine_head  routine_body {
        //printf("routine reduced.\n");
        $$ = (char*)(new routine_s);
        ((routine_s*)$$)->routine_head = (routine_head_s*)$1;
        ((routine_s*)$$)->routine_body = (routine_body_s*)$2;
};
routine_head : const_part  type_part  var_part  routine_part{
	    $$ = (char*)(new routine_head_s);
        ((routine_head_s*)$$)->const_part = (const_part_s*)$1;
        ((routine_head_s*)$$)->type_part = (type_part_s*)$2;
        ((routine_head_s*)$$)->var_part = (var_part_s*)$3;
        ((routine_head_s*)$$)->routine_part = (routine_part_s*)$4;
};
const_part : _CONST const_expr_list {
        $$ = (char*)(new const_part_s);
        vector<const_expr_list_s*>& lst = ((const_part_s*)$$)->const_expr_list;
        lst.clear();
        for(const_expr_list_s* p = (const_expr_list_s*)$2; p; p=p->next)
             lst.push_back(p);
     }
       | {
         $$ = NULL; 
};
const_expr_list : const_expr_list  _ID  _EQUAL  const_value _SEMI {
            $$ = (char*)(new const_expr_list_s);
            ((const_expr_list_s*)$$)->next = (const_expr_list_s*)$1;
            ((const_expr_list_s*)$$)->ID = string($2);
            ((const_expr_list_s*)$$)->const_value = (const_value_s*)$4;
        }
     |  _ID  _EQUAL  const_value  _SEMI {
            $$ = (char*)(new const_expr_list_s);
            ((const_expr_list_s*)$$)->next = NULL;
            ((const_expr_list_s*)$$)->ID = string($1);
            ((const_expr_list_s*)$$)->const_value = (const_value_s*)$3;
};
const_value : _INTEGER_NUM 
                { $$ = (char*)(new const_value_s); ((const_value_s*)$$)->VALUE = string($1); ((const_value_s*)$$)->TYPE = const_value_s::INTEGER;
                    //printf("const value (INTEGER %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
            | _REAL_NUM 
                { $$ = (char*)(new const_value_s); ((const_value_s*)$$)->VALUE = string($1); ((const_value_s*)$$)->TYPE = const_value_s::REAL;
                    //printf("const value (REAL %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
            | _CHAR_NUM 
                { $$ = (char*)(new const_value_s); ((const_value_s*)$$)->VALUE = string($1); ((const_value_s*)$$)->TYPE = const_value_s::CHAR;
                    //printf("const value (CHAR %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
            | _STRING_NUM 
                { $$ = (char*)(new const_value_s); ((const_value_s*)$$)->VALUE = string($1); ((const_value_s*)$$)->TYPE = const_value_s::STRING;
                    //printf("const value (STRING %s) reduced.\n",((const_value_s*)$$)->VALUE.c_str()); 
                    }
;
type_part : _TYPE type_decl_list {
              $$ = (char*)(new type_part_s);
              vector<type_definition_s*>& lst = ((type_part_s*)$$)->type_definition;
              for(type_decl_list_s* p = (type_decl_list_s*)$2; p; p=p->next)
                lst.push_back(p->type_definition);
            } 
    | { $$ = NULL; 
};
type_decl_list : type_decl_list type_definition {
        $$ = (char*)(new type_decl_list_s);
        ((type_decl_list_s*)$$)->next = (type_decl_list_s*)$1;
        ((type_decl_list_s*)$$)->type_definition = (type_definition_s*)$2; } 
    | type_definition {
        $$ = (char*)(new type_decl_list_s);
        ((type_decl_list_s*)$$)->next = NULL;
        ((type_decl_list_s*)$$)->type_definition = (type_definition_s*)$1;
};
type_definition : _ID _EQUAL type_decl _SEMI {
        $$ = (char*)(new type_definition_s);
        ((type_definition_s*)$$)->ID = string($1);
        ((type_definition_s*)$$)->type_decl = (type_decl_s*)$3;
};
type_decl : simple_type_decl {
        $$ = (char*)(new type_decl_s);
        ((type_decl_s*)$$)->simple_type_decl = (simple_type_decl_s*)$1;
        ((type_decl_s*)$$)->array_type_decl = NULL;
        ((type_decl_s*)$$)->record_type_decl = NULL;
          }
      | array_type_decl {
        $$ = (char*)(new type_decl_s);
        ((type_decl_s*)$$)->simple_type_decl = NULL;
        ((type_decl_s*)$$)->array_type_decl = (array_type_decl_s*)$1;
        ((type_decl_s*)$$)->record_type_decl = NULL;
            }
      | record_type_decl {
        $$ = (char*)(new type_decl_s);
        ((type_decl_s*)$$)->simple_type_decl = NULL;
        ((type_decl_s*)$$)->array_type_decl = NULL;
        ((type_decl_s*)$$)->record_type_decl = (record_type_decl_s*)$1;
};
simple_type_decl :  _SYS_TYPE {
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::SYS_TYPE;
                    ((simple_type_decl_s*)$$)->SYS_TYPE_NAME = string($1);
                 }
                 | _ID { 
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::ID_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)$$)->ID;
                    lstID.clear();
                    lstID.push_back(string($1));
                 }
                 | _ID _DOT _DOT _ID { 
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::RANGE_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)$$)->ID;
                    lstID.clear();
                    lstID.push_back(string($1));
                    lstID.push_back(string($4));
                 }
                 | const_value _DOT _DOT const_value { 
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s 
                        *a = (const_value_s*)$1, *b = (const_value_s*)$2;
                    if(a->TYPE!=b->TYPE)
                        yyerror("different type in RANGE declaration");
                    else if(a->TYPE==const_value_s::REAL)
                        yyerror("REAL is no allowed in RANGE declaration");
                    else if(a->TYPE==const_value_s::STRING)
                        yyerror("STRING is no allowed in RANGE declaration");
                    else if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)$$)->MIN = str2int(a->VALUE);
                        ((simple_type_decl_s*)$$)->MAX = str2int(b->VALUE);
                    }
                    else if(a->TYPE==const_value_s::CHAR)
                    {
                        ((simple_type_decl_s*)$$)->MIN = (int)str2char(a->VALUE);
                        ((simple_type_decl_s*)$$)->MAX = (int)str2char(b->VALUE);
                    }
                 }
                 | _MINUS const_value _DOT _DOT const_value {
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s *a = (const_value_s*)$2, *b = (const_value_s*)$5;
                    if(a->TYPE!=b->TYPE) yyerror("different type in RANGE declaration");
                    if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)$$)->MIN = -str2int(a->VALUE);
                        ((simple_type_decl_s*)$$)->MAX = str2int(b->VALUE);
                    }
                    else yyerror("expect integer");
                 }
                 | _MINUS const_value _DOT _DOT _MINUS const_value { 
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::RANGE_TYPE;

                    const_value_s *a = (const_value_s*)$2, *b = (const_value_s*)$6;
                    if(a->TYPE!=b->TYPE) yyerror("different type in RANGE declaration");
                    if(a->TYPE==const_value_s::INTEGER)
                    {
                        ((simple_type_decl_s*)$$)->MIN = -str2int(a->VALUE);
                        ((simple_type_decl_s*)$$)->MAX = -str2int(b->VALUE);
                    }
                    else yyerror("expect integer");
                 }
                 | _LP name_list _RP { 
                    $$ = (char*)(new simple_type_decl_s);
                    ((simple_type_decl_s*)$$)->TYPE = simple_type_decl_s::ENUM_TYPE;
                    vector<string>& lstID = ((simple_type_decl_s*)$$)->ID;
                    lstID.clear();
                    for(name_list_s* p = (name_list_s*)$1; p; p=p->next)
                        lstID.push_back(p->ID);
                        
};
array_type_decl : _ARRAY _LB simple_type_decl _RB _OF type_decl {
                $$ = (char*)(new array_type_decl_s);
                ((array_type_decl_s*)$$)->simple_type_decl = (simple_type_decl_s*)$3;
                ((array_type_decl_s*)$$)->type_decl = (type_decl_s*)$6;
};

record_type_decl : _RECORD field_decl_list _END{
                $$ = (char*)(new record_type_decl_s);
                vector<field_decl_s*>& lst = ((record_type_decl_s*)$$)->field_decl;
                lst.clear();
                for(field_decl_list_s* p = (field_decl_list_s*)$2; p; p=p->next)
                    lst.push_back(p->field_decl);
};
field_decl_list : field_decl_list field_decl {
                    $$ = (char*)(new field_decl_list_s);
                    ((field_decl_list_s*)$$)->next = (field_decl_list_s*)$1;
                    ((field_decl_list_s*)$$)->field_decl = (field_decl_s*)$2;
                }
                | field_decl{
                    $$ = (char*)(new field_decl_list_s);
                    ((field_decl_list_s*)$$)->next = NULL;
                    ((field_decl_list_s*)$$)->field_decl = (field_decl_s*)$1;
};
field_decl : name_list _COLON type_decl _SEMI {
                    $$ = (char*)(new field_decl_s);
                    ((field_decl_s*)$$)->type_decl = (type_decl_s*)$3;
                    vector<string>& lst = ((field_decl_s*)$$)->name_list;
                    for(name_list_s* p = (name_list_s*)$1; p; p=p->next)
                        lst.push_back(p->ID);
};
name_list : name_list _COMMA _ID {
                    $$ = (char*)(new name_list_s);
                    ((name_list_s*)$$)->next = (name_list_s*)$1;
                    ((name_list_s*)$$)->ID = string($3);
             }
             | _ID{
                    $$ = (char*)(new name_list_s);
                    ((name_list_s*)$$)->next = NULL;
                    ((name_list_s*)$$)->ID = string($1);
};

var_part : _VAR var_decl_list {
            $$ = (char*)(new var_part_s);
            vector<var_decl_s*>& lst = ((var_part_s*)$$)->var_decl;
            lst.clear();
            for(var_decl_list_s* p = (var_decl_list_s*)$2; p; p=p->next)
                lst.push_back(p->var_decl);
         }
         | {
             $$ = NULL; 
};

var_decl_list : var_decl_list var_decl {
            $$ = (char*)(new var_decl_list_s);
            ((var_decl_list_s*)$$)->next = (var_decl_list_s*)$1;
            ((var_decl_list_s*)$$)->var_decl = (var_decl_s*)$2;
                }
        | var_decl {
            $$ = (char*)(new var_decl_list_s);
            ((var_decl_list_s*)$$)->next = NULL;
            ((var_decl_list_s*)$$)->var_decl = (var_decl_s*)$1;
};

var_decl : name_list _COLON type_decl _SEMI {
            $$ = (char*)(new var_decl_s);                    
            vector<string>& lst = ((var_decl_s*)$$)->name_list;
            for(name_list_s* p = (name_list_s*)$1; p; p=p->next)
                lst.push_back(p->ID);
            ((var_decl_s*)$$)->type_decl = (type_decl_s*)$2;
};
        
routine_part :  routine_part  function_decl {
                $$ = (char*)(new routine_part_s);
                ((routine_part_s*)$$)->next = (routine_part_s*)$1;
                ((routine_part_s*)$$)->procedure_decl = NULL;
                ((routine_part_s*)$$)->function_decl = (function_decl_s*)$2;
             }
             |  routine_part  procedure_decl {
                $$ = (char*)(new routine_part_s);
                ((routine_part_s*)$$)->next = (routine_part_s*)$1;
                ((routine_part_s*)$$)->procedure_decl = (procedure_decl_s*)$2;
                ((routine_part_s*)$$)->function_decl = NULL;
             }
             |  function_decl {
                $$ = (char*)(new routine_part_s);
                ((routine_part_s*)$$)->next = NULL;
                ((routine_part_s*)$$)->procedure_decl = NULL;
                ((routine_part_s*)$$)->function_decl = (function_decl_s*)$1;
             }
             |  procedure_decl {
                $$ = (char*)(new routine_part_s);
                ((routine_part_s*)$$)->next = NULL;
                ((routine_part_s*)$$)->procedure_decl = (procedure_decl_s*)$1;
                ((routine_part_s*)$$)->function_decl = NULL;
             } | { $$ = NULL;
};



function_decl : function_head _SEMI routine _SEMI {
                $$ = (char*)(new function_decl_s);
                ((function_decl_s*)$$)->function_head = (function_head_s*)$1;
                ((function_decl_s*)$$)->routine = (routine_s*)$3;
};

function_head : _FUNCTION _ID parameters _COLON simple_type_decl {
                $$ = (char*)(new function_head_s);
                ((function_head_s*)$$)->ID = string($2);
                ((function_head_s*)$$)->parameters = (parameters_s*)$5;
                ((function_head_s*)$$)->simple_type_decl = (simple_type_decl_s*)$3;
};

procedure_decl : procedure_head _SEMI routine _SEMI {
                $$ = (char*)(new procedure_decl_s);
                ((procedure_decl_s*)$$)->procedure_head = (procedure_head_s*)$1;
                ((procedure_decl_s*)$$)->routine = (routine_s*)$3;
};

procedure_head : _PROCEDURE _ID parameters {
                $$ = (char*)(new procedure_decl_s);
                ((function_head_s*)$$)->ID = string($2);
                ((function_head_s*)$$)->parameters = (parameters_s*)$3;
};


parameters : _LP para_decl_list _RP {
                $$ = (char*)(new parameters_s);
                vector<para_type_list_s*>& lst = ((parameters_s*)$$)->para_decl_list;
                lst.clear();
                for(para_decl_list_s* p = ((para_decl_list_s*)$2); p; p=p->next)
                    lst.push_back(p->para_type_list);
           }
        |{
            $$ = NULL;
};

para_decl_list : para_decl_list _SEMI para_type_list {
            $$ = (char*)(new para_decl_list_s);
            ((para_decl_list_s*)$$)->next = (para_decl_list_s*)$1;
            ((para_decl_list_s*)$$)->para_type_list = (para_type_list_s*)$2;
                 }
            |   para_type_list {
            $$ = (char*)(new para_decl_list_s);
            ((para_decl_list_s*)$$)->next = NULL;
            ((para_decl_list_s*)$$)->para_type_list = (para_type_list_s*)$1;
};

para_type_list : var_para_list _COLON simple_type_decl {
            $$ = (char*)(new para_type_list_s);
            ((para_type_list_s*)$$)->var_para_list = (var_para_list_s*)$1;
            ((para_type_list_s*)$$)->val_para_list = NULL;
            ((para_type_list_s*)$$)->simple_type_decl = (simple_type_decl_s*)$3;

               }
            | val_para_list _COLON simple_type_decl {
            $$ = (char*)(new para_type_list_s);
            ((para_type_list_s*)$$)->val_para_list = (val_para_list_s*)$1;
            ((para_type_list_s*)$$)->var_para_list = NULL;
            ((para_type_list_s*)$$)->simple_type_decl = (simple_type_decl_s*)$3;
};

var_para_list : _VAR name_list {
            $$ = (char*)(new var_para_list_s);
            ((var_para_list_s*)$$)->name_list = (name_list_s*)$1;
};
             
val_para_list : name_list {
            $$ = (char*)(new val_para_list_s);
            ((val_para_list_s*)$$)->name_list = (name_list_s*)$1;
};

routine_body : compound_stmt {
            //printf("routine_body reduced.\n");
            $$ = (char*)(new routine_body_s);
            ((routine_body_s*)$$)->compound_stmt = (compound_stmt_s*)$1;
};

compound_stmt : _BEGIN stmt_list _END {
            //printf("compound_stmt reduced.\n");
            $$ = (char*)(new compound_stmt_s);
            vector<stmt_s*> &lst = ((compound_stmt_s*)$$)->stmt;
            lst.clear();
            for(stmt_list_s* p = (stmt_list_s*)$2; p; p=p->next)
                lst.push_back(p->stmt);
            //printf("[compound_stmt]the number of stmt: %d\n",(int)lst.size());
};

stmt_list : stmt_list stmt _SEMI {
            //printf("stmt_list reduced.\n");
            $$ = (char*)(new stmt_list_s);
            ((stmt_list_s*)$$)->next = (stmt_list_s*)$1;
            ((stmt_list_s*)$$)->stmt = (stmt_s*)$2; }
          | { $$ = NULL;
};

stmt : _INTEGER_NUM _COLON non_label_stmt {
            //printf("stmt reduced.\n");
            $$ = (char*)(new stmt_s);
            ((stmt_s*)$$)->INTEGER = new int;
            *(((stmt_s*)$$)->INTEGER) = str2int(string($1));
            //printf("[stmt]label:%d\n",*((stmt_s*)$$)->INTEGER);
            ((stmt_s*)$$)->non_label_stmt = (non_label_stmt_s*)$3;
       } | non_label_stmt {
            //printf("stmt reduced.\n");
            $$ = (char*)(new stmt_s);
            ((stmt_s*)$$)->INTEGER = NULL;
            ((stmt_s*)$$)->non_label_stmt = (non_label_stmt_s*)$1;
};

non_label_stmt : assign_stmt {
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = (assign_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
 }
| proc_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = (proc_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
}
| compound_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = (compound_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
}
| if_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = (if_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
}
| repeat_stmt {
               //printf("non_label_stmt reduced.\n");    
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = (repeat_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
 } 
| while_stmt {
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = (while_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
 }
| for_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = (for_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
}
| case_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = (case_stmt_s*)$1;
               ((non_label_stmt_s*)$$)->goto_stmt = NULL;
}
| goto_stmt { 
               //printf("non_label_stmt reduced.\n");
               $$ = (char*)(new non_label_stmt_s);
               ((non_label_stmt_s*)$$)->assign_stmt = NULL;
               ((non_label_stmt_s*)$$)->proc_stmt = NULL;
               ((non_label_stmt_s*)$$)->compound_stmt = NULL;
               ((non_label_stmt_s*)$$)->if_stmt = NULL;
               ((non_label_stmt_s*)$$)->repeat_stmt = NULL;
               ((non_label_stmt_s*)$$)->while_stmt = NULL;
               ((non_label_stmt_s*)$$)->for_stmt = NULL;
               ((non_label_stmt_s*)$$)->case_stmt = NULL;
               ((non_label_stmt_s*)$$)->goto_stmt = (goto_stmt_s*)$1;
};


assign_stmt : _ID  _ASSIGN  expression {
               //printf("assign_stmt reduced.\n");
               $$ = (char*)(new assign_stmt_s);
               ((assign_stmt_s*)$$)->ID = string($1);
               ((assign_stmt_s*)$$)->expression_idx = NULL;
               ((assign_stmt_s*)$$)->expression = (expression_s*)$3;
               ((assign_stmt_s*)$$)->ID_DOT_ID = NULL;
               ((assign_stmt_s*)$$)->TYPE = 0;
               //printf("[assign_stmt]%s := expression\n", $1);
            }
           | _ID _LB expression _RB _ASSIGN expression {
               //printf("assign_stmt reduced.\n");
               $$ = (char*)(new assign_stmt_s);
               ((assign_stmt_s*)$$)->ID = string($1);
               ((assign_stmt_s*)$$)->expression_idx = (expression_s*)$3;
               ((assign_stmt_s*)$$)->expression = (expression_s*)$6;
               ((assign_stmt_s*)$$)->ID_DOT_ID = NULL;
               ((assign_stmt_s*)$$)->TYPE = 1;
               //printf("[assign_stmt]%s[expression] := expression\n", $1);
}
           | _ID  _DOT  _ID  _ASSIGN  expression {
               //printf("assign_stmt reduced.\n");
               $$ = (char*)(new assign_stmt_s);
               //((assign_stmt_s*)$$)->ID = string($1);
               ((assign_stmt_s*)$$)->expression_idx = NULL;
               ((assign_stmt_s*)$$)->expression = (expression_s*)$4;
               ((assign_stmt_s*)$$)->ID_DOT_ID = new pair<string,string>(string($1),string($3));
               ((assign_stmt_s*)$$)->TYPE = 2;
               //printf("[assign_stmt]%s.%s := expression\n", $1, $3);
};

proc_stmt : _ID {
             //printf("proc_stmt reduced.\n");    
             $$ = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)$$)->ID = string($1);
             ((proc_stmt_s*)$$)->args_list = NULL;
             ((proc_stmt_s*)$$)->readID = "";
             //printf("[proc_stmt]%s\n", $1);             
        }
        | _ID _LP args_list _RP {
             //printf("proc_stmt reduced.\n");                
             $$ = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)$$)->ID = string($1);
             ((proc_stmt_s*)$$)->args_list = (args_list_s*)$3;
             ((proc_stmt_s*)$$)->readID = "";
             //printf("[proc_stmt]%s(args_list)\n", $1);                          
        }
        | _SYS_PROC {
             //printf("proc_stmt reduced.\n");                
             $$ = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)$$)->ID = string($1);
             ((proc_stmt_s*)$$)->args_list = NULL;
             ((proc_stmt_s*)$$)->readID = "";
             //printf("[proc_stmt]%s--SYS_PROC\n", $1);                                       
        }
        | _SYS_PROC _LP args_list _RP {
             //printf("proc_stmt reduced.\n");                
             $$ = (char*)(new proc_stmt_s);
             ((proc_stmt_s*)$$)->ID = string($1);
             ((proc_stmt_s*)$$)->args_list = (args_list_s*)$3;
             ((proc_stmt_s*)$$)->readID = "";
             //printf("[proc_stmt]%s(args_list)--SYS_PROC\n", $1);                                                    
        }
        | _READ _LP _ID _RP {
             //printf("proc_stmt reduced.\n");                
             $$ = (char*)(new proc_stmt_s);
             //((proc_stmt_s*)$$)->ID = string($3);
             ((proc_stmt_s*)$$)->args_list = NULL;
             ((proc_stmt_s*)$$)->readID = string($3);
             //printf("[proc_stmt]READ(%s)--READ\n", $1);                                                                 
};

if_stmt : _IF  expression  _THEN  compound_stmt  else_clause {
             $$ = (char*)(new if_stmt_s);
             ((if_stmt_s*)$$)->expression = (expression_s*)$2;
             ((if_stmt_s*)$$)->compound_stmt = (compound_stmt_s*)$4;
             ((if_stmt_s*)$$)->else_clause = (else_clause_s*)$5;
};

else_clause : _ELSE compound_stmt {
            $$ = (char*)(new else_clause_s);
            ((else_clause_s*)$$)->compound_stmt = (compound_stmt_s*)$2;
        } | { $$ = NULL;
};

repeat_stmt : _REPEAT stmt_list _UNTIL expression {
            $$ = (char*)(new repeat_stmt_s);
            ((repeat_stmt_s*)$$)->expression = (expression_s*)$4;
            vector<stmt_s*>& lst = ((repeat_stmt_s*)$$)->stmt;
            lst.clear();
            for(stmt_list_s* p = (stmt_list_s*)$2; p; p=p->next)
                lst.push_back(p->stmt);
};

while_stmt : _WHILE expression _DO compound_stmt {
            $$ = (char*)(new while_stmt_s);
            ((while_stmt_s*)$$)->expression = (expression_s*)$2;
            ((while_stmt_s*)$$)->compound_stmt = (compound_stmt_s*)$4;
 };

for_stmt : _FOR  _ID  _ASSIGN  expression  direction  expression  _DO compound_stmt {
            $$ = (char*)(new for_stmt_s);
            ((for_stmt_s*)$$)->ID = string($2);
            ((for_stmt_s*)$$)->direction = (for_stmt_s::directionEnum)((direction_s*)$5)->dir;
            ((for_stmt_s*)$$)->expression1 = (expression_s*)$4;
            ((for_stmt_s*)$$)->expression2 = (expression_s*)$6;
            ((for_stmt_s*)$$)->compound_stmt = (compound_stmt_s*)$8;
 };

direction : _TO {
            $$ = (char*)(new direction_s);
            ((direction_s*)$$)->dir = 0;
         } | _DOWNTO {
            $$ = (char*)(new direction_s);
            ((direction_s*)$$)->dir = 1;
};

case_stmt : _CASE expression _OF case_expr_list _END {
            $$ = (char*)(new case_stmt_s);
            ((case_stmt_s*)$$)->expression = (expression_s*)$2;
            vector<case_expr_s*>& lst = ((case_stmt_s*)$$)->case_expr;
            lst.clear();
            for(case_expr_list_s* p = (case_expr_list_s*)$4; p; p=p->next)
                lst.push_back(p->case_expr);
};

case_expr_list : case_expr_list case_expr {
            $$ = (char*)(new case_expr_list_s);
            ((case_expr_list_s*)$$)->next= (case_expr_list_s*)$1;
            ((case_expr_list_s*)$$)->case_expr = (case_expr_s*)$2;
       } | case_expr {
            $$ = (char*)(new case_expr_list_s);
            ((case_expr_list_s*)$$)->next = NULL;
            ((case_expr_list_s*)$$)->case_expr = (case_expr_s*)$1;
};

case_expr : const_value  _COLON  stmt  _SEMI {
            $$ = (char*)(new case_expr_s);
            ((case_expr_s*)$$)->const_value = (const_value_s*)$1;
            ((case_expr_s*)$$)->stmt = (stmt_s*)$3;
            ((case_expr_s*)$$)->ID = NULL;

          } |  _ID  _COLON  stmt  _SEMI {
            $$ = (char*)(new case_expr_s);
            ((case_expr_s*)$$)->ID = new string($1);
            ((case_expr_s*)$$)->const_value = NULL;
            ((case_expr_s*)$$)->stmt = (stmt_s*)$3;
};

goto_stmt : _GOTO _INTEGER_NUM {
            $$ = (char*)(new goto_stmt_s);
            ((goto_stmt_s*)$$)->INTEGER = str2int(string($2));
};

expression : expression  _GE  expr {
            //printf("expression GE reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::GE;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expression _GT  expr {
            //printf("expression GT reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::GT;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expression  _LE  expr {
            //printf("expression LE reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::LE;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expression  _LT  expr {
            //printf("expression LT reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::LT;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expression  _EQUAL  expr {
            //printf("expression EQUAL reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::EQUAL;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expression  _UNEQUAL  expr {
            //printf("expression UNEQUAL reduced.\n");
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::UNEQUAL;
            ((expression_s*)$$)->next = (expression_s*)$1;
            ((expression_s*)$$)->expr = (expr_s*)$3;
         }  |  expr {
            $$ = (char*)(new expression_s);
            ((expression_s*)$$)->TYPE = expression_s::NULL_OPERATOR;
            ((expression_s*)$$)->next = NULL;
            ((expression_s*)$$)->expr = (expr_s*)$1;
            //printf("expression (expr) reduced.\n");
};
             
expr : expr _PLUS term {
            //printf("expr (+) reduced.\n");
            $$ = (char*)(new expr_s);
            ((expr_s*)$$)->TYPE = expr_s::PLUS;
            ((expr_s*)$$)->next = (expr_s*)$1;
            ((expr_s*)$$)->term = (term_s*)$3;
    }  |  expr  _MINUS  term {
            //printf("expr (-) reduced.\n");
            $$ = (char*)(new expr_s);
            ((expr_s*)$$)->TYPE = expr_s::MINUS;
            ((expr_s*)$$)->next = (expr_s*)$1;
            ((expr_s*)$$)->term = (term_s*)$3;
    }  |  expr  _OR  term {
            //printf("expr (OR) reduced.\n");            
            $$ = (char*)(new expr_s);
            ((expr_s*)$$)->TYPE = expr_s::OR;
            ((expr_s*)$$)->next = (expr_s*)$1;
            ((expr_s*)$$)->term = (term_s*)$3;
    }  |  term {
            //printf("expr (term) reduced.\n");
            $$ = (char*)(new expr_s);
            ((expr_s*)$$)->TYPE = expr_s::NULL_OPERATOR;
            ((expr_s*)$$)->next = NULL;
            ((expr_s*)$$)->term = (term_s*)$1;
};

term : term  _MUL  factor {
            //printf("term (*) reduced.\n");
            $$ = (char*)(new term_s);
            ((term_s*)$$)->TYPE = term_s::MUL;
            ((term_s*)$$)->next = (term_s*)$1;
            ((term_s*)$$)->factor = (factor_s*)$3;
   }  |  term  _DIV  factor {
            //printf("term (/) reduced.\n");            
            $$ = (char*)(new term_s);
            ((term_s*)$$)->TYPE = term_s::DIV;
            ((term_s*)$$)->next = (term_s*)$1;
            ((term_s*)$$)->factor = (factor_s*)$3;
   }  |  term  _MOD  factor { 
            //printf("term (MOD) reduced.\n");            
            $$ = (char*)(new term_s);
            ((term_s*)$$)->TYPE = term_s::MOD;
            ((term_s*)$$)->next = (term_s*)$1;
            ((term_s*)$$)->factor = (factor_s*)$3;
   }  |  term  _AND  factor {
            //printf("term (AND) reduced.\n");                        
            $$ = (char*)(new term_s);
            ((term_s*)$$)->TYPE = term_s::AND;
            ((term_s*)$$)->next = (term_s*)$1;
            ((term_s*)$$)->factor = (factor_s*)$3;
   }  |  factor {
            //printf("term (factor) reduced.\n");                        
            $$ = (char*)(new term_s);
            ((term_s*)$$)->TYPE = term_s::NULL_OPERATOR;
            ((term_s*)$$)->next = NULL;
            ((term_s*)$$)->factor = (factor_s*)$1;
};

factor : _ID  {
            //printf("factor (ID) reduced.\n");                        
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::ID_TYPE;
            ((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("[factor]%s\n",((factor_s*)$$)->ID.c_str());
     } |  _ID  _LP  args_list  _RP {
            //printf("factor reduced.\n");                        
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::FUNCTION_WITH_ARGS;
            ((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = (args_list_s*)$3;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("[factor]%s(args_list)\n",((factor_s*)$$)->ID.c_str());            
     } |  _SYS_FUNC {
            //printf("factor reduced.\n");                        
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::SYS_FUNCT;
            ((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("[factor]%s---SYS_FUNC\n",((factor_s*)$$)->ID.c_str());                        
     } |  _SYS_FUNC  _LP  args_list  _RP  {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::SYS_FUNCT_WITH_ARGS;
            ((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = (args_list_s*)$3;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("factor reduced.\n");
            //printf("[factor]%s(args_list)---SYS_FUNC\n",((factor_s*)$$)->ID.c_str());                                    
     } |  const_value {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::CONST_VALUE;
            //((factor_s*)$$)->ID = "nothing";
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = (const_value_s*)$1;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("factor (const_value) reduced.\n");
     } |  _LP  expression  _RP {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::EXPRESSION;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = (expression_s*)$2;
            ((factor_s*)$$)->next = NULL;
            //printf("factor (expression) reduced.\n");            
     } |  _NOT  factor {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::NOT_FACTOR;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = (factor_s*)$2;
            //printf("factor (NOT factor) reduced.\n");            
     } |  _MINUS  factor {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::NOT_FACTOR;
            //((factor_s*)$$)->ID = "";
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = (factor_s*)$2;
            //printf("factor (- factor) reduced.\n");            
     } |  _ID  _LB  expression  _RB {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::ID_WITH_EXPRESSION;
            ((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = NULL;
            ((factor_s*)$$)->expression = (expression_s*)$3;
            ((factor_s*)$$)->next = NULL;
            //printf("factor %s[expression] reduced.\n",((factor_s*)$$)->ID.c_str());            
     } |  _ID  _DOT  _ID {
            $$ = (char*)(new factor_s);
            ((factor_s*)$$)->TYPE = factor_s::ID_DOT_ID_TYPE;
            //((factor_s*)$$)->ID = string($1);
            ((factor_s*)$$)->args_list = NULL;
            ((factor_s*)$$)->const_value = NULL;
            ((factor_s*)$$)->ID_DOT_ID = new pair<string,string>(string($1),string($3));
            ((factor_s*)$$)->expression = NULL;
            ((factor_s*)$$)->next = NULL;
            //printf("factor %s.%s reduced.\n",((factor_s*)$$)->ID_DOT_ID->first.c_str(),((factor_s*)$$)->ID_DOT_ID->second.c_str());                        
};

args_list : args_list  _COMMA  expression {
            $$ = (char*)(new args_list_s);
            ((args_list_s*)$$)->next = (args_list_s*)$1;
            ((args_list_s*)$$)->expression = (expression_s*)$3;
         } |  expression {
            $$ = (char*)(new args_list_s);
            ((args_list_s*)$$)->next = NULL;
            ((args_list_s*)$$)->expression = (expression_s*)$1;
};

%%


void yyerror(const char *s)
{
    printf("%d %s\n",line_no,s);
}

int main(int argc, char* args[])
{
    extern FILE* yyin, *out;
    string filename;
    if(argc==1)
        cin >> filename;
    else
        filename = string(args[1]);
    yyin = fopen(filename.c_str(), "r");
    if (yyin == NULL) {
        printf("cannot open pascal.pas\n");
        system("Pause");
        return 0;
    }
    yyparse();
    
    //yacc test
    extern void outputCode(program_s&);
    outputCode(program);
    
    /*code generation*/
    
    fclose(yyin);
    return 0;
}
