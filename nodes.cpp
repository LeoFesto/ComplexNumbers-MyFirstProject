#include "nodes.h"


double Number::GetResult() const {
	return number;
}

Operation::Operation(char oper) : sign(oper) {
	if (sign == '+' or sign == '-')
		priority = 1;
	else if (sign == '*' or sign == '/')
		priority = 2;
	else if (sign == '(')
		priority = 0;
	else if (sign == ')')
		priority = 3;
}

double Operation::GetResult() const {
	if (sign == '+')
		return left_ptr->GetResult() + right_ptr->GetResult();
	else if (sign == '-')
		return left_ptr->GetResult() - right_ptr->GetResult();
	else if (sign == '*')
		return left_ptr->GetResult() * right_ptr->GetResult();
	else if (sign == '/')
		return left_ptr->GetResult() / right_ptr->GetResult();
	else
		throw exception();
}



