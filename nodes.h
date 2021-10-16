#pragma once
#include "token.h"
#include <memory>

struct Node {
	virtual double GetResult() const = 0;
	Node() = default;
};


struct Number : public Node {
	Number(double n) : number(n) {};
	double GetResult() const override;
private:
	const double number;
};


struct Operation : public Node {
	Operation(char oper);
	double GetResult() const override;
	int priority;
	char sign;
	shared_ptr<Node>left_ptr;
	shared_ptr<Node>right_ptr;
};