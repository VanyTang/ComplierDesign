#!/bin/sh
clear
rm ./comp.log
rm ./mycomp
rm ./*~
lex cd_lex_yacc.l &>comp.log
yacc cd_yacc_cgen.y -d &>>comp.log
cp ./lex.yy.c ./Project/codeGenerate/codeGenerate/lex.yy.cpp
cp ./y.tab.c ./Project/codeGenerate/codeGenerate/y.tab.cpp
