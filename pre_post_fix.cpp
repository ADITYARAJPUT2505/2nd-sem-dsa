#include <iostream>
#include <stack>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> operandStack;

    for (int i = 0; i < expression.length(); ++i) {
    	char c = expression[i];
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c != ' ') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result;

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    exit(EXIT_FAILURE);
            }

            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int evaluatePrefix(string expression) {
    stack<int> operandStack;

    for (int i = expression.size() - 1; i >= 0; i--) {
        char c = expression[i];
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c != ' ') {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            int result;

            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    exit(EXIT_FAILURE);
            }

            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    string expression;
    cout << "Enter a postfix or prefix expression: ";
    getline(cin, expression);

    // Determine if the expression is postfix or prefix based on the first character
    char firstChar = expression[0];
    bool isPostfix = (firstChar == '+' || firstChar == '-' || firstChar == '*' || firstChar == '/');

    int result;
    if (isPostfix) {
        result = evaluatePostfix(expression);
    } else {
        // Reverse the prefix expression to treat it as postfix expression
        reverse(expression.begin(), expression.end());
        result = evaluatePrefix(expression);
    }

    cout << "Result: " << result << endl;

    return 0;
}

