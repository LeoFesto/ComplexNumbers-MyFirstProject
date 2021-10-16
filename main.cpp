#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <memory>
#include <string>

#include "token.h"
#include "nodes.h"
#include "parser.h"
#include "test_runner.h"
#include "tests.h"

using namespace std;


int main() {
	
	Parser parser;
	string expression;
	while (true) {
		try {
			cout << "Enter the expression: " << endl;
			getline(cin, expression);
			if (expression == "stop" or expression == "STOP")
				break;
			else {
				cout << parser.ChangeExpression(expression).Result() << endl;
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}
	return 0;
}




