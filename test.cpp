#include "cd_yacc_node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void var_decl(var_decl_s* node)
{
    for(begin(node->name_list),end(node->name_list),[](const string& str){
            cout << str << ",";
    });
    cout << ":";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void var_part(var_part_s* node)
{
    if(node==NULL) return;
    cout << "VAR ";
    for(begin(node->var_decl),end(node->var_decl),[](const (var_decl_s*)& p){
            var_decl(p);
    });
}
void field_decl(field_decl_s* node)
{
    for(begin(node->name_list),end(node->name_list),[](const string& str){
            cout << str << ",";
    });
    cout << ":";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void record_type_decl(record_type_decl_s* node)
{
    cout << "RECORD ";
    for(begin(node->field_decl),end(node->field_decl),[](const (field_decl_s*)& p){
            field_decl(p);
    });
    cout << "END" << endl;
}

void array_type_decl(array_type_decl_s* node)
{
    cout << "ARRAY [";
    simple_type_decl(node->simple_type_decl);
    cout << "] OF";
    type_decl(node->type_decl);
}

void simple_type_decl(simple_type_decl_s* node)
{
    if(node->TYPE==simple_type_decl_s::SYS_TYPE)
        cout << SYS_TYPE_NAME;
    else if(node->TYPE==simple_type_decl_s::ID_TYPE)
        cout << ID[0];
    else if(node->TYPE==simple_type_decl_s::ENUM_TYPE)
    {
        cout << "(";
        for(begin(node->ID),end(node->end),[](const string& str){
                cout << str << ',';
        });
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
        //TODO
    }
    else if(node->record_type_decl!=NULL)
    {
        //TODO
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
    cout << "TYPE ";
    for(begin(node->type_definition),end(node->type_definition),
           [](const (type_definition_s*)& p){
        type_definition(p);           
    });
    cout << endl;
}
void const_value(const_value_s* node)
{
    cout << node->VALUE;
}
void const_expr_list(const_expr_list_s* node)
{
    if(node->next!=NULL);
        const_expr_list(node->next);
    cout << " " << node->ID << " = ";
    const_value(node->const_value);
    cout << ";" << endl;;
}
void const_part(const_part_s* node)
{
    if(node==NULL) return;
    cout << "CONST " << endl;
    for(begin(node->const_expr_list),end(node->const_expr_list),
        [](const (const_expr_list_s*)& p){
            const_expr_list(p);
    });
}

void routine_head(routine_head_s* node)
{
    const_part(node->const_part);
    type_part(node->type_part);
    var_part(node->var_type_part);
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
