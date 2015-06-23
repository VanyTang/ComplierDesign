#include "cd_yacc_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void stmt(stmt_s* node);
void compound_stmt(compound_stmt_s* node);
void routine_body(routine_body_s* node);
void para_type_list(para_type_list_s* node);
void name_list(name_list_s* node);
void parameters(parameters_s* node);
void procedure_decl(procedure_decl_s* node);
void function_decl(function_decl_s* node);
void routine_part(routine_part_s* node);
void var_decl(var_decl_s* node);
void var_part(var_part_s* node);
void field_decl(field_decl_s* node);
void record_type_decl(record_type_decl_s* node);
void array_type_decl(array_type_decl_s* node);
void simple_type_decl(simple_type_decl_s* node);
void type_decl(type_decl_s* node);
void type_definition(type_definition_s* node);
void type_part(type_part_s* node);
void const_value(const_value_s* node);
void const_expr_list(const_expr_list_s* node);
void const_part(const_part_s* node);
void routine_head(routine_head_s* node);
void routine(routine_s* node);
void program (program_s* node);


void stmt(stmt_s* node)
{

}

void compound_stmt(compound_stmt_s* node)
{
    cout << "BEGIN" << endl;
    vector<stmt_s*>::iterator p = node->stmt.begin();
    for(;p != node->stmt.end(); p++)
        stmt(*p);
    cout << "END" << endl;
}
void routine_body(routine_body_s* node)
{
    compound_stmt(node->compound_stmt);
}
void para_type_list(para_type_list_s* node)
{
    if(node->var_para_list!=NULL) 
    {
        cout << "VAR " << endl;
        name_list(node->var_para_list->name_list);
    }
    else 
    {
        name_list(node->val_para_list->name_list);
    }
    cout << " : ";
    simple_type_decl(node->simple_type_decl);
}
void name_list(name_list_s* node)
{
    if(node!=NULL)
    {
        stringstream ss("");
        for(name_list_s* p = node; p; p=p->next)
            ss << p->ID << ",";
        string str(ss.str());
        cout << str.substr(0,str.size()-1);
    }
}
void parameters(parameters_s* node)
{
    vector<para_type_list_s*>::iterator p = node->para_decl_list.begin();
    for(;p != node->para_decl_list.end(); p++)
    {
        para_type_list(*p);
        cout << " ; ";
    }
}
void procedure_decl(procedure_decl_s* node)
{
    cout << "PROCEDURE" << node->procedure_head->ID << " ";
    parameters(node->procedure_head->parameters);
    cout << " ;" << endl;
    routine(node->routine);
    cout << " ;" << endl;
}
void function_decl(function_decl_s* node)
{
    cout << "FUNCTION " << node->function_head->ID;
    parameters(node->function_head->parameters);
    cout << " : ";
    simple_type_decl(node->function_head->simple_type_decl);
    cout << " ;" << endl;
    routine(node->routine);
    cout << " ;" << endl;
}
void routine_part(routine_part_s* node)
{
    if(node==NULL) return;
    if(node->next!=NULL) routine_part(node->next);
    if(node->procedure_decl!=NULL) procedure_decl(node->procedure_decl);
    if(node->function_decl!=NULL) function_decl(node->function_decl);
}

void var_decl(var_decl_s* node)
{
    stringstream ss;
    vector<string>::iterator p;
    for(p = node->name_list.begin(); p!=node->name_list.end();++p)
        ss << *p << ",";
    string str(ss.str());
    cout << str.substr(0,str.size()-1) << " : ";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void var_part(var_part_s* node)
{
    if(node==NULL) return;
    cout << "VAR ";
    vector<var_decl_s*>::iterator p = node->var_decl.begin();
    for(; p!=node->var_decl.end();++p)
        var_decl(*p);
}
void field_decl(field_decl_s* node)
{
    stringstream ss;
    vector<string>::iterator p = node->name_list.begin();
    for( ;p!=node->name_list.end();++p)
        ss << *p << ",";
    string str(ss.str());
    cout << str.substr(0,str.size()-1) << " : ";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void record_type_decl(record_type_decl_s* node)
{
    cout << "RECORD" << endl;
    vector<field_decl_s*>::iterator p = node->field_decl.begin();
    for(; p!=node->field_decl.end();++p)
        field_decl(*p);
    cout << "END";
}
void array_type_decl(array_type_decl_s* node)
{
    cout << "ARRAY [";
    simple_type_decl(node->simple_type_decl);
    cout << " ] OF ";
    type_decl(node->type_decl);
    cout << endl;
}
void simple_type_decl(simple_type_decl_s* node)
{
    if(node->TYPE==simple_type_decl_s::SYS_TYPE)
        cout << node->SYS_TYPE_NAME;
    else if(node->TYPE==simple_type_decl_s::ID_TYPE)
        cout << node->ID[0];
    else if(node->TYPE==simple_type_decl_s::ENUM_TYPE)
    {
        cout << "(";
        vector<string>::iterator p;
        for(p = node->ID.begin(); p!=node->ID.end();++p)
                cout << *p << ",";
        cout << ")";
    }
    else if(node->TYPE==simple_type_decl_s::RANGE_TYPE)
    {
        if(node->ID.size()!=0)//ID..ID
            cout << node->ID[0] << ".." << node->ID[1];
        else // (+-)value..(+-)value
            cout << node->MIN << ".." << node->MAX;
    }
}
void type_decl(type_decl_s* node)
{
    if(node->simple_type_decl!=NULL)
    {
        simple_type_decl(node->simple_type_decl);
    }
    else if(node->array_type_decl!=NULL)
    {
        array_type_decl(node->array_type_decl);
    }
    else if(node->record_type_decl!=NULL)
    {
        record_type_decl(node->record_type_decl);
    }
}
void type_definition(type_definition_s* node)
{
    cout << node->ID << " = ";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void type_part(type_part_s* node)
{
    if(node==NULL) return;
    cout << "TYPE " << endl;
    vector<type_definition_s*>::iterator p;
    for(p = node->type_definition.begin();p != node->type_definition.end(); p++)
        type_definition(*p);
    cout << endl;
}
void const_value(const_value_s* node)
{
    cout << node->VALUE;
}
void const_expr_list(const_expr_list_s* node)
{
    if(node->next!=NULL)
        const_expr_list(node->next);
    cout << " " << node->ID << " = ";
    const_value(node->const_value);
    cout << ";" << endl;;
}
void const_part(const_part_s* node)
{
    if(node==NULL) return;
    cout << "CONST " << endl;
    vector<const_expr_list_s*>::iterator p;
    for(p = node->const_expr_list.begin();p != node->const_expr_list.end(); p++)
        const_expr_list(*p);
    cout << endl;
}

void routine_head(routine_head_s* node)
{
    const_part(node->const_part);
    type_part(node->type_part);
    var_part(node->var_part);
    routine_part(node->routine_part);
}

void routine(routine_s* node)
{
    routine_head(node->routine_head);
    routine_body(node->routine_body);
}

void program (program_s* node)
{
    cout << "PROGRAM " << node->ID << ';' << endl;
    routine(node->routine);
}

void outputCode(program_s& prog)
{
    program(&prog);
}
