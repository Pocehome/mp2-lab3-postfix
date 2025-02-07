﻿#include "postfix.h"

int main() {
	std::string expression = "((1+3)/2)-(2+4)/2";
	double res = 0.0;

	TArithmeticExpression postfix(expression);
	std::cout << expression << std::endl;
	std::cout << "Expression: " << postfix.getInfix() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix() << std::endl;
	res = postfix.calculate();
	std::cout << "Result: " << res << std::endl;

	return 0;
}

//void main() {
//	TStack<int> stack;
//	stack.push(10);
//	stack.push(100);
//	stack.push(1000);
//	TStack<int> st(stack);
//	std::cout << st << std::endl;
//}