#pragma once
#include <vector>
#include "AstScript.h"


using namespace std;
extern int iterationLabel;
class BlockStatement : public Statement {
	Statement *statement;
public:
	explicit BlockStatement(Statement *statement):statement(statement){}
	void dump(int indent) override {
		label(indent, "BlockStatement\n");
		statement->dump(indent + 1);
	}
	void GenCode(FILE* file) override {
		statement->GenCode(file);
	}
};

class Block : public Statement {
	StatementList *stmtList;
public:
	explicit Block(StatementList *stmtList):stmtList(stmtList){}
	void dump(int indent) override {
		label(indent, "Block\n");
		stmtList->dump(indent + 1);
	}
	void GenCode(FILE* file) override {
		stmtList->GenCode(file);
	}
};

class ExpressionStatement : public Statement {
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *expression):expression(expression){}
	void dump(int indent) override{
		label(indent, "ExpressionStatement\n");
		expression->dump(indent + 1);
	}
	void GenCode(FILE* file) override {
		expression->GenCode(file);
	};
};

class IfStatement : public Statement {
	Expression *cond;
	Statement *thenStmt;
	Statement *elseStmt;
public:
	explicit IfStatement(Expression *cond, Statement *thenStmt, Statement *elseStmt):cond(cond), thenStmt(thenStmt), elseStmt(elseStmt){}
	explicit IfStatement(Expression *cond, Statement *thenStmt):cond(cond), thenStmt(thenStmt)
	{
		elseStmt = nullptr;
	}
	void dump(int indent) override {
		label(indent, "IfStatement\n");
		cond->dump(indent + 1, "cond");
		thenStmt->dump(indent + 1, "then");
		if (elseStmt != nullptr)
		{
			elseStmt->dump(indent + 1, "else");
		}
	}
	void GenCode(FILE* file) override {
		int refno;
		refno = cond->GenCode(file);
		emit(file, "if (GetValue(r%d)->ToBoolean()) {", refno);
		thenStmt->GenCode(file);
		emit(file, "}");
		if (elseStmt != nullptr) {
			emit(file, "else {");
			elseStmt->GenCode(file);
			emit(file, "}");
		}
	}
};

class BreakableStatement :public Statement
{
	Statement *stmt;
public:
	explicit BreakableStatement(Statement *stmt):stmt(stmt){}
	void dump(int indent) override {
		label(indent, "BreakableStatement\n");
		stmt->dump(indent + 1);
	}
	void GenCode(FILE* file) override {
		stmt->GenCode(file);
	}

};
class IterationStatement: public Statement
{
	Statement *stmt;
public:
	explicit IterationStatement(Statement *stmt) :stmt(stmt) {}
	void dump(int indent) override {
		label(indent, "IterationStatement\n");
		stmt->dump(indent + 1);
	}
	void GenCode(FILE* file) override {
		stmt->GenCode(file);
	}
};
class DoWhileStatement:public Statement
{
	Statement *stmt;
	Expression *cond;
public:
	DoWhileStatement(Statement *stmt,Expression *cond):stmt(stmt),cond(cond){}
	void dump(int indent) override {
		label(indent, "DoWhileStatement\n");
		stmt->dump(indent + 1, "stmt");
		cond->dump(indent + 1, "cond");
		
	}
	void GenCode(FILE* file) override {
		emit(file, "DoWhileLabel%d:", iterationLabel);
		stmt->GenCode(file);
		int refno = cond->GenCode(file);
		emit(file, "if (GetValue(r%d)->ToBoolean()) {", refno);
		emit(file, "goto DoWhileLabel%d;", iterationLabel);
		emit(file, "}");
	}
};
class WhileStatement:public Statement
{
	Statement *stmt;
	Expression *cond;
public:
	WhileStatement(Statement *stmt, Expression *cond) :stmt(stmt), cond(cond) {}
	void dump(int indent) override {
		label(indent, "WhileStatement\n");
		stmt->dump(indent + 1, "stmt");
		cond->dump(indent + 1, "cond");
	}
	void GenCode(FILE* file) override {		
		int refno = cond->GenCode(file);
		emit(file, "WhileLabel%d:", iterationLabel);
		emit(file, "if (GetValue(r%d)->ToBoolean()) {", refno);
		stmt->GenCode(file);
		emit(file, "goto DoWhileLabel%d;", iterationLabel);
		emit(file, "}");
	}
};