#define _CRT_SECURE_NO_DEPRECATE
#include <Types/LanguageTypes/LanguageTypesFunc.h>
#include <Utilities/Operator/Operator.h>
#include <parser.h>

//#define AST
#define SA

extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {

#ifdef AST
	fopen_s(&yyin, argv[1], "r");
	yyparse();
#endif

#ifdef SA
	_calculate(new StringType("Hello"), "+", new NullType());
	_calculate(new NumberType(50), "-", new BooleanType(false));
	_calculate(new NullType(), "*", new NumberType(20));
	_calculate(new BooleanType(true), "/", new StringType("1000"));
	_calculate(new StringType("20"), "%", new NumberType(5));
#endif

}
