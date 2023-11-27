#include "postfix.h"

int main() {
	std::string expression = "((1+3)/2)-(2+4)/2";
	double res = 0.0;

	//std::cout << "Enter expression: ";
	//std::getline(std::cin, expression);
	TArithmeticExpression postfix(expression);
	std::cout << expression << std::endl;
	std::cout << "Expression: " << postfix.getInfix() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix() << std::endl;
	res = postfix.calculate();
	std::cout << "Result: " << res << std::endl;

	return 0;
}

//void main() {
//	int arr[] = { 1, 2, 3, 4, 5 };
//	TStack<int> st(3);
//	st.push(3);
//	st.push(6);
//	st.push(1);
//	for (size_t i = 0; i < 3; i++) {
//		std::cout << st.top() << std::endl;
//		st.pop();
//	}
//}
