#include "postfix.h"

void TArithmeticExpression::parse() {
	for (char c : infix) {
		lexemes.push_back(c);
	}
}

void TArithmeticExpression::toPostfix() {
	parse();
	TStack<char> st;
	char stackItem;

	for (char item : lexemes) {
		switch (item) {
		case '(':
			st.push(item);
			break;

		case ')':
			stackItem = st.top();
			st.pop();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.top();
				st.pop();
			}
			break;

		case '+': case '-': case '*': case '/':
			while (!st.isEmpty()) {
				stackItem = st.top();
				st.pop();
				if (priority[item] <= priority[stackItem]) {
					postfix += stackItem;
				}
				else {
					st.push(stackItem);
					break;
				}
			}
			st.push(item);
			break;

		default:
			operands.insert({ item, item - '0' });
			postfix += item;
			break;
		}
	}
	while (!st.isEmpty()) {
		stackItem = st.top();
		st.pop();
		postfix += stackItem;
	}
}

TArithmeticExpression::TArithmeticExpression(std::string expression) : infix(expression) {
	priority = { { '+', 1}, { '-', 1}, { '*', 2}, { '/', 2}, { '(', 0 } };
	toPostfix();
}

std::vector<char> TArithmeticExpression::getOperands() const {
	std::vector<char> oper;
	for (const auto& item : operands) {
		oper.push_back(item.first);
	}
	return oper;
}

double TArithmeticExpression::calculate() {
	TStack<double> stack;
	double leftOperand, rightOperand;

	for (char lexem : postfix) {
		switch (lexem) {
		case '+':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand + rightOperand);
			/*std::cout << stack << std::endl;
			std::cout << leftOperand << "+" << rightOperand << "=" << leftOperand + rightOperand << std::endl << std::endl;*/
			break;
		case '-':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand - rightOperand);
			/*std::cout << stack << std::endl;
			std::cout << leftOperand << "-" << rightOperand << "=" << leftOperand - rightOperand << std::endl << std::endl;*/
			break;
		case '*':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand * rightOperand);
			/*std::cout << stack << std::endl;
			std::cout << leftOperand << "*" << rightOperand << "=" << leftOperand * rightOperand << std::endl << std::endl;*/
			break;
		case '/':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand / rightOperand);
			/*std::cout << stack << std::endl;
			std::cout << leftOperand << "/" << rightOperand << "=" << leftOperand / rightOperand << std::endl << std::endl;*/
			break;
		default:
			stack.push(operands[lexem]);
			/*std::cout << operands[lexem] << std::endl;
			std::cout << stack << std::endl;*/
			break;
		}
	}
	return stack.top();
}