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
void expression(expression_s* node);


void args_list(args_list_s* node)
{
    if(node->next!=NULL)
    {
        args_list(node->next);
        cout << ", ";
        expression(node->expression);
    }
    else
        expression(node->expression);
}
void factor(factor_s* node)
{
    switch(node->TYPE)
    {
        case factor_s::MINUS_FACTOR: 
            cout << "-"; factor(node->next); break;
        case factor_s::NOT_FACTOR: 
            cout << "NOT "; factor(node->next); break;
        case factor_s::ID_TYPE:
            cout << node->ID; break;
        case factor_s::FUNCTION_WITH_ARGS: case factor_s::SYS_FUNCT_WITH_ARGS:
            cout << node->ID << "(";
            args_list(node->args_list);
            cout<< ")";
            break;
        case factor_s::SYS_FUNCT:
            cout << node->ID;
            break;
        case factor_s::CONST_VALUE:
            const_value(node->const_value);
            break;
        case factor_s::EXPRESSION:
            expression(node->expression);
            break;
        case factor_s::ID_WITH_EXPRESSION:
            cout << node->ID << "[";
            args_list(node->args_list);
            cout<< "]";
            break;
        case factor_s::ID_DOT_ID_TYPE:
            cout << node->ID_DOT_ID->first << "." << node->ID_DOT_ID->second;
            break;
    }
}
void term(term_s* node)
{
    if(node->next!=NULL) term(node->next);
    switch(node->TYPE)
    {
        case term_s::MUL: cout << " * "; break;
        case term_s::DIV: cout << " / "; break;
        case term_s::MOD: cout << " MOD "; break;
        case term_s::AND: cout << " AND "; break;
        case term_s::NULL_OPERATOR: break;
    }
    factor(node->factor);
}
void expr(expr_s* node)
{
    if(node->next!=NULL) expr(node->next);
    switch(node->TYPE)
    {
        case expr_s::PLUS: cout << " + "; break;
        case expr_s::MINUS: cout << " - "; break;
        case expr_s::OR: cout << " OR "; break;
        case expr_s::NULL_OPERATOR: break;
    }
    term(node->term);
}

void expression(expression_s* node)
{
    if(node->next!=NULL) expression(node->next);
    switch(node->TYPE)
    {
        case expression_s::GE: cout << " >= "; break;
        case expression_s::GT: cout << " > "; break;
        case expression_s::LE: cout << " <= "; break;
        case expression_s::LT: cout << " < "; break;
        case expression_s::EQUAL: cout << " = "; break;
        case expression_s::UNEQUAL: cout << " <> "; break;
        case expression_s::NULL_OPERATOR: break;
    }
    expr(node->expr);
}
void stmt(stmt_s* node)
{
    if(node->INTEGER!=NULL)
        cout << *node->INTEGER << ": " << endl;
    non_label_stmt_s* p = node->non_label_stmt;
    if(p->assign_stmt!=NULL)
    {
        assign_stmt_s* ps = p->assign_stmt;
        switch(ps->TYPE)
        {
            case 0:
                cout << ps->ID << " := ";
                expression(ps->expression);
                break;
            case 1:
                cout << ps->ID << "[";
                expression(ps->expression_idx);
                cout << "]" << " := ";
                expression(ps->expression);
                break;
            case 2:
                cout << ps->ID_DOT_ID->first << "." << ps->ID_DOT_ID->second;
                cout << " := ";
                expression(ps->expression);
                break;
        }
    }
    else if(p->proc_stmt!=NULL)
    {
        cout << p->proc_stmt->ID;
        if(p->proc_stmt->args_list!=NULL)
        {
            cout << "(";
            args_list(p->proc_stmt->args_list);
            cout << ")";
        }
        if(p->proc_stmt->ID=="read")
        {
            cout << "(" << p->proc_stmt->readID << ")";
        }
    }
    else if(p->compound_stmt!=NULL)
    {
        compound_stmt(p->compound_stmt);
    }
    else if(p->if_stmt!=NULL)
    {
        cout << "IF ";
        expression(p->if_stmt->expression);
        cout << " THEN" << endl;
        compound_stmt(p->if_stmt->compound_stmt);
        if(p->if_stmt->else_clause!=NULL)
        {
            cout << endl << "ELSE" << endl;
            compound_stmt(p->if_stmt->else_clause->compound_stmt);
        }
    }
    else if(p->repeat_stmt!=NULL)
    {
        cout << "REPEAT " << endl;
        vector<stmt_s*>::reverse_iterator it =p->repeat_stmt->stmt.rbegin();
        for(;it != p->repeat_stmt->stmt.rend(); ++it)
            stmt(*it);
        cout << "UNTIL ";
        expression(p->repeat_stmt->expression);
    }
    else if(p->while_stmt!=NULL)
    {
        cout << "WHILE ";
        expression(p->while_stmt->expression);
        cout << " DO" << endl;
        compound_stmt(p->while_stmt->compound_stmt);
    }
    else if(p->for_stmt!=NULL)
    {
        cout << "FOR " << p->for_stmt->ID << " := ";
        expression(p->for_stmt->expression1);
        switch(p->for_stmt->direction)
        {
            case for_stmt_s::TO: cout << " TO "; break;
            case for_stmt_s::DOWNTO: cout << " DOWNTO "; break;
        }
        expression(p->for_stmt->expression2);
        cout << " DO" << endl;
        compound_stmt(p->for_stmt->compound_stmt);
    }
    else if(p->case_stmt!=NULL)
    {
        cout << "CASE ";
        expression(p->case_stmt->expression);
        cout << " OF" << endl;

        vector<case_expr_s*>::reverse_iterator it = p->case_stmt->case_expr.rbegin();
        for(;it != p->case_stmt->case_expr.rend();++it)
        {
            case_expr_s* ps = *it;
            if(ps->const_value!=NULL)
            {
                const_value(ps->const_value);
                cout << ": ";
                stmt(ps->stmt);
            }
            else
            {
                cout << *(ps->ID);
                cout << ": ";
                stmt(ps->stmt);
            }
        }
        cout << "END";
    }
    else if(p->goto_stmt!=NULL)
    {
        cout << "goto " << p->goto_stmt->INTEGER;
    }
    cout << ";"  << endl;
}

void compound_stmt(compound_stmt_s* node)
{
    cout << "BEGIN" << endl;
    vector<stmt_s*>::reverse_iterator p = node->stmt.rbegin();
    for(;p != node->stmt.rend(); p++)
        stmt(*p);
    cout << "END";
}
void routine_body(routine_body_s* node)
{
    compound_stmt(node->compound_stmt);
}
void para_type_list(para_type_list_s* node)
{
    if(node->var_para_list!=NULL) 
    {
        cout << "VAR ";
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
        for(name_list_s* p = node; p; p=p->next)
            cout << p->ID << ",";
        cout << '\b';
    }
}
void parameters(parameters_s* node)
{
    if(node==NULL) return;
    cout << "(";
    vector<para_type_list_s*>::reverse_iterator p = node->para_decl_list.rbegin();
    for(;p != node->para_decl_list.rend(); p++)
    {
        para_type_list(*p);
        cout << "; ";
    }
    cout << "\b\b)";
}
void procedure_decl(procedure_decl_s* node)
{
    cout << "PROCEDURE " << node->procedure_head->ID << " ";
    parameters(node->procedure_head->parameters);
    cout << ";" << endl;
    routine(node->routine);
    cout << ";" << endl << endl;
}
void function_decl(function_decl_s* node)
{
    cout << "FUNCTION " << node->function_head->ID;
    parameters(node->function_head->parameters);
    cout << " : ";
    simple_type_decl(node->function_head->simple_type_decl);
    cout << ";" << endl;
    routine(node->routine);
    cout << ";" << endl << endl;;
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
    vector<string>::reverse_iterator p;
    for(p = node->name_list.rbegin(); p!=node->name_list.rend();++p)
        cout << *p << ",";
    cout << "\b : ";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void var_part(var_part_s* node)
{
    if(node==NULL) return;
    cout << "VAR ";
    vector<var_decl_s*>::reverse_iterator p = node->var_decl.rbegin();
    for(; p!=node->var_decl.rend();++p)
        var_decl(*p);
    cout << endl;
}
void field_decl(field_decl_s* node)
{
    vector<string>::reverse_iterator p = node->name_list.rbegin();
    for( ;p!=node->name_list.rend();++p)
        cout << *p << ",";
    cout << "\b : ";
    type_decl(node->type_decl);
    cout << ";" << endl;
}
void record_type_decl(record_type_decl_s* node)
{
    cout << "RECORD" << endl;
    vector<field_decl_s*>::reverse_iterator p = node->field_decl.rbegin();
    for(; p!=node->field_decl.rend();++p)
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
        vector<string>::reverse_iterator p;
        for(p = node->ID.rbegin(); p!=node->ID.rend();++p)
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
    vector<type_definition_s*>::reverse_iterator p;
    for(p = node->type_definition.rbegin();p != node->type_definition.rend(); p++)
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
    vector<const_expr_list_s*>::reverse_iterator p;
    for(p = node->const_expr_list.rbegin();p != node->const_expr_list.rend(); p++)
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
    cout << "." << endl;
}

void outputCode(program_s& prog)
{
    program(&prog);
}
