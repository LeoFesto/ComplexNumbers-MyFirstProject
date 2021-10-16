#include "parser.h"

vector<Token> Parser::Tokenize(const string& expression) {
	vector<Token> tokens;
	istringstream is(expression);
	while (is.eof() != true) {
		string value;
		is >> value;
		if (value == "(" or value == ")" or value == "+" or value == "-" or value == "*" or value == "/") {
			tokens.push_back({ value, TokenType::OPERATION });
		}
		else {
			bool IsValueNumber = true;
			for (auto digit_ptr = value.begin(); digit_ptr != value.end(); digit_ptr++) {
				char symbol = *digit_ptr;
				if ((symbol < '0' or symbol > '9') and symbol != '.' and symbol != '-') {
					IsValueNumber = false;
					break;
				}
			}
			(IsValueNumber == true) ? tokens.push_back({ value, TokenType::NUMBER }) : throw invalid_argument("Incorrect input");
		}
	}
	return tokens;
}


double Parser::Parse(vector<Token> tokens) {
	stack<shared_ptr<Node>>nodes;
	stack<shared_ptr<Operation>>operations;

	auto PerformLastOperation = [&]() {
		shared_ptr<Operation>operation = operations.top();
		operations.pop();
		shared_ptr<Node>rhs = nodes.top();
		nodes.pop();
		shared_ptr<Node>lhs = nodes.top();
		nodes.pop();
		operation->left_ptr = lhs;
		operation->right_ptr = rhs;
		nodes.push(operation);
	};

	for (auto token_ptr = tokens.begin(); token_ptr != tokens.end(); token_ptr++) {
		if (token_ptr->type == TokenType::OPERATION) {
			char sign = token_ptr->value[0];
			Operation operation(sign);
			if (operations.empty() != true) {
				if (operation.priority > operations.top()->priority) {
					if (operation.sign == ')') {
						while (operations.top()->sign != '(') {
							PerformLastOperation();
						}
						operations.pop();
					}
					else
						operations.push(make_shared<Operation>(operation));
				}
				else {
					if(operation.sign == '(')
						operations.push(make_shared<Operation>(operation));
					else {
						while (operations.empty() != true and operation.priority <= operations.top()->priority) {
							if (operations.top()->sign == '(') {
								break;
							}
							else
								PerformLastOperation();
						}
						operations.push(make_shared<Operation>(operation));
					}
				}
			}
			else
				operations.push(make_shared<Operation>(operation));
		}
		else if (token_ptr->type == TokenType::NUMBER) {
			double num = stod(token_ptr->value);
			nodes.push(make_shared<Number>(num));
		}
	}

	while (operations.empty() != true) {
		PerformLastOperation();
	}
	shared_ptr<Node>result_node_ptr;
	(nodes.size() == 1) ? result_node_ptr = nodes.top() : throw exception("Something went wrong.");

	return result_node_ptr->GetResult();
}

Parser::Parser(const string& expr) : str_expression(expr) {
	tokens = Tokenize(str_expression);
};

double Parser::Result() {
	result_of_expression = Parse(tokens);
	return result_of_expression;
}

string Parser::GetExpression(){
	return str_expression;
}

Parser Parser::ChangeExpression(const string& expr){
	*this = Parser(expr);
	return *this;
}

