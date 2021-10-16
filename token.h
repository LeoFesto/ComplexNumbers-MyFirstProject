#pragma once
#include <string>
using namespace std;

enum class TokenType {
	NUMBER,
	OPERATION
};

struct Token {
	string value;
	TokenType type;
};
