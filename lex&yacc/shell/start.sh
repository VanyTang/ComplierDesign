#!/bin/sh
clear
rm ../log/comp.log
rm ../bin/mycomp
lex ../cd_lex_yacc.l &>../log/comp.log
yacc ../cd_yacc_cgen.y -d &>>../log/comp.log
cp lex.yy.c ../lex.yy.c
rm lex.yy.c
cp y.tab.c ../y.tab.c
rm y.tab.c
cp y.tab.h ../y.tab.h
rm y.tab.h
g++ ../lex.yy.c ../y.tab.c ../test.cpp -o ../bin/mycomp -g -ly -ll &>>../log/comp.log
tail ../log/comp.log
../bin/mycomp ../testcode/test0.pas
