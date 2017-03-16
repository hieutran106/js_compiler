#define _CRT_SECURE_NO_DEPRECATE 
#include <cstdio>
#include <y.tab.h>

int yylex();
YYSTYPE yylval;
extern FILE *yyin;

using namespace std;
void main(int argc, char *argv[]) {
	int token;
	yyin = fopen(argv[1], "r");
	do {
		token = yylex();
		printf("Next Token: ");
		switch (token) {

			// JIN - START -------------------------------------------------------

			case BREAK: puts("BREAK");
				break;
			case DO: puts("DO");
				break;
			case IN: puts("IN");
				break;
			case TYPEOF: puts("TYPEOF");
				break;
			case CASE: puts("CASE");
				break;
			case ELSE: puts("ELSE");
				break;
			case INSTANCEOF: puts("INSTANCEOF");
				break;
			case VAR: puts("VAR");
				break;
			case CATCH: puts("CATCH");
				break;
			case EXPORT: puts("EXPORT");
				break;
			case NEW: puts("NEW");
				break;
			case VOID: puts("VOID");
				break;
			case CLASS: puts("CLASS");
				break;
			case EXTENDS: puts("EXTENDS");
				break;
			case RETURN: puts("RETURN");
				break;
			case WHILE: puts("WHILE");
				break;
			case CONST: puts("CONST");
				break;
			case FINALLY: puts("FINALLY");
				break;
			case SUPER: puts("SUPER");
				break;
			case WITH: puts("WITH");
				break;
			case CONTINUE: puts("CONTINUE");
				break;
			case FOR: puts("FOR");
				break;
			case SWITCH: puts("SWITCH");
				break;
			case YIELD: puts("YIELD");
				break;
			case DEBUGGER: puts("DEBUGGER");
				break;
			case FUNCTION: puts("FUNCTION");
				break;
			case THIS: puts("THIS");
				break;
			case DEFAULT: puts("DEFAULT");
				break;
			case IF: puts("IF");
				break;
			case THROW: puts("THROW");
				break;
			case DELETE: puts("DELETE");
				break;
			case IMPORT: puts("IMPORT");
				break;
			case TRY: puts("TRY");
				break;
			case AWAIT: puts("AWAIT");
				break;
			case ENUM: puts("ENUM");
				break;
			case TDOT: puts("'...'");
				break;
			case LE: puts("'<='");
				break;
			case GE: puts("'>='");
				break;
			case EQ: puts("'=='");
				break;
			case DIFF: puts("'!='");
				break;
			case EQTYPE: puts("'==='");
				break;
			case DFTYPE: puts("'!=='");
				break;
			case INCREASE: puts("'++'");
				break;
			case DECREASE: puts("'--'");
				break;
			case LSHIFT: puts("'<<'");
				break;
			case RSHIFT: puts("'>>'");
				break;
			case URSHIFT: puts("'>>>'");
				break;
			case LOGAND: puts("'&&'");
				break;
			case LOOR: puts("'||'");
				break;
			case ADDASS: puts("'+='");
				break;
			case SUBASS: puts("'-='");
				break;
			case MULASS: puts("'*='");
				break;
			case REMASS: puts("'%='");
				break;
			case LSHIFTASS: puts("'<<='");
				break;
			case RSHIFTASS: puts("'>>='");
				break;
			case URSHIFTASS: puts("'>>>='");
				break;
			case BWANDASS: puts("'&='");
				break;
			case BWORASS: puts("'|='");
				break;
			case BWXORASS: puts("'^='");
				break;
			case ARROWF: puts("'=>'");
				break;
			case EXP: puts("'**'");
				break;
			case EXPASS: puts("'**='");
				break;
			case DIVASS: puts("'/='");
				break;

			// JIN - END -------------------------------------------------------

			case 0:
				puts("EOF");
				break;
			default:
				printf("'%c'\n", token);
				break;
		}
	} while (token != 0);
}
