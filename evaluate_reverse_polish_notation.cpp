/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/

#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                if (token == "+") operands.push(a + b);
                else if (token == "-") operands.push(a - b);
                else if (token == "*") operands.push(a * b);
                else operands.push(a / b);
            } else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
};