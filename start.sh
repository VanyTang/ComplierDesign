#!/bin/sh
clear
rm ./comp.log
rm ./mycomp
lex cd_lex_yacc.l &>comp.log
yacc cd_yacc_cgen.y -d &>>comp.log
g++ -std=c++11 lex.yy.c y.tab.c test.cpp -o mycomp -g -ly -ll &>>comp.log
tail comp.log
./mycomp ./testcode/test0.pas
