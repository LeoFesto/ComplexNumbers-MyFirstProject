#pragma once
#include<vector>
#include <sstream>
#include <stack>
#include "token.h"
#include "nodes.h"



class Parser {
private:
	vector<Token> Tokenize(const string& expression);
	double Parse(vector<Token> tokens);

public:
	Parser() = default;
	Parser(const string& expr);
	double Result();
	string GetExpression();
	Parser ChangeExpression(const string& expr);

private:
	string str_expression;
	double result_of_expression;
	vector<Token>tokens;
};


