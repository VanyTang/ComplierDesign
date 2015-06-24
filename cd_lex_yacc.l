%{
	#define YYSTYPE char*
        #include "y.tab.h"
	#include <stdio.h>
	#include <string.h>
        using namespace std;

        int line_no = 1;

        extern "C" {
            int yywrap(void);
            int yylex(void);
        }

%}

A	[Aa]
B	[Bb]
C	[Cc]
D	[Dd]
E	[Ee]
F	[Ff]
G	[Gg]
H	[Hh]
I	[Ii]
J	[Jj]
K	[Kk]
L	[Ll]
M	[Mm]
N	[Nn]
O	[Oo]
P	[Pp]
Q	[Qq]
R	[Rr]
S	[Ss]
T	[Tt]
U	[Uu]
V	[Vv]
W	[Ww]
X	[Xx]
Y	[Yy]
Z	[Zz]
ID      [a-zA-Z\_][a-zA-Z0-9\_]*
Digit   [0-9]
NQUOTE	[^']

%%

"("		return(_LP);
")"		return(_RP);
"["		return(_LB);
"]"		return(_RB);
"." 	        return(_DOT);
":"		return(_COLON);
","		return(_COMMA_SIGN);
";"		return(_SEMI);
"*"		return(_MUL);
"+"		return(_PLUS);
"-"		return(_MINUS);
">="	        return(_GE);
">"		return(_GT);
"<="	        return(_LE);
"<"		return(_LT);
"="		return(_EQUAL);
"<>"		return(_UNEQUAL);
"/"		return(_DIV);
":="	        return(_ASSIGN);

{A}{B}{S}				{yylval=strdup(yytext);return(_SYS_FUNC);}
{C}{H}{R}				{yylval=strdup(yytext);return(_SYS_FUNC);}
{O}{R}{D}				{yylval=strdup(yytext);return(_SYS_FUNC);}
{O}{D}{D}				{yylval=strdup(yytext);return(_SYS_FUNC);}
{P}{R}{E}{D}			{yylval=strdup(yytext);return(_SYS_FUNC);}
{S}{U}{C}{C}			{yylval=strdup(yytext);return(_SYS_FUNC);}
{S}{Q}{R}				{yylval=strdup(yytext);return(_SYS_FUNC);}
{S}{Q}{R}{T}			{yylval=strdup(yytext);return(_SYS_FUNC);}
{W}{R}{I}{T}{E}			{yylval=strdup(yytext);return(_SYS_PROC);}
{W}{R}{I}{T}{E}{L}{N}	{yylval=strdup(yytext);return(_SYS_PROC);}

{F}{A}{L}{S}{E}					{yylval=strdup(yytext);return(_SYS_CON);}
{T}{R}{U}{E}					{yylval=strdup(yytext);return(_SYS_CON);}
{M}{A}{X}{I}{N}{T}				{yylval=strdup(yytext);return(_SYS_CON);}

{I}{N}{T}{E}{G}{E}{R}			{yylval=strdup(yytext);return(_SYS_TYPE);}
{R}{E}{A}{L}					{yylval=strdup(yytext);return(_SYS_TYPE);}
{B}{O}{O}{L}{E}{A}{N}			{yylval=strdup(yytext);return(_SYS_TYPE);}
{C}{H}{A}{R}					{yylval=strdup(yytext);return(_SYS_TYPE);}
{S}{T}{R}{I}{N}{G}				{yylval=strdup(yytext);return(_SYS_TYPE);}

{D}{O}							return(_DO);
{T}{O}							return(_TO);
{I}{F}							return(_IF);
{O}{R}							return(_OR);
{O}{F}							return(_OF);
{E}{N}{D}						return(_END);
{F}{O}{R}						return(_FOR);
{V}{A}{R}						return(_VAR);
{N}{O}{T}						return(_NOT);
{A}{N}{D}						return(_AND);
{M}{O}{D}                                           return (_MOD);
{T}{Y}{P}{E}                                            return (_TYPE);
{E}{L}{S}{E}					return(_ELSE);
{R}{E}{A}{D}					return(_READ);
{C}{A}{S}{E}					return(_CASE);
{T}{H}{E}{N}					return(_THEN);
{G}{O}{T}{O}					return(_GOTO);
{A}{R}{R}{A}{Y}					return(_ARRAY);
{B}{E}{G}{I}{N}					return(_BEGIN);
{U}{N}{T}{I}{L}					return(_UNTIL);
{W}{H}{I}{L}{E}					return(_WHILE);
{C}{O}{N}{S}{T}					return(_CONST);
{R}{E}{P}{E}{A}{T}				return(_REPEAT);
{R}{E}{C}{O}{R}{D}				return(_RECORD);
{D}{O}{W}{N}{T}{O}				return(_DOWNTO);
{P}{R}{O}{G}{R}{A}{M}			return(_PROGRAM);
{P}{R}{O}{C}{E}{D}{U}{R}{E}		return(_PROCEDURE);
{F}{U}{N}{C}{T}{I}{O}{N}		return(_FUNCTION);

{ID}                  { yylval=strdup(yytext); return(_ID); }
({Digit}+)"."({Digit}+) { yylval=strdup(yytext); return(_REAL_NUM); }
{Digit}+ { yylval=strdup(yytext); return(_INTEGER_NUM); }
"'"{NQUOTE}"'"      { yylval=strdup(yytext); return(_CHAR_NUM); }
"'"{NQUOTE}+"'"      { yylval=strdup(yytext); return(_STRING_NUM); }

\n                      ++line_no;
    
%%

int yywrap()
{
	return 1;
}

