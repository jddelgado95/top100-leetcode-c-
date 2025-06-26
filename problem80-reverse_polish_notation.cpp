/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-java/

1. Create an empty stack
2. Push operands into the stack
3. If you find an operator like *, + , - , / ...
4. Then pop the two elements from the stack, and apply the operator to them
5. Push the result
5. Repeat
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Create the stack
        stack<int> stack;

        for(const string& token: tokens){
            if(isOperator(token)) {
                //Pop operands
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                //Implement the operations on the recently popped operands
                int result = evaluate(token, operand1, operand2);
                stack.push(result);
            } else {
                stack.push(stoi(token));
            }
        }
        //Return the result of the operations which is the top of the stack
        return stack.top();
    }

    bool isOperator(const string& token){
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evaluate(const string& token, int operand1, int operand2) {
        if(token == "+") {
            return operand1 + operand2;
        } else if (token == "-") {
            return operand1 - operand2;
        } else if(token == "*"){
            return operand1 * operand2;
        } else if(token == "/"){
            return operand1 / operand2;
        } else {
            return 0;
        }

    }
};

int main() {
    Solution solution;

    // Example: ["2", "1", "+", "3", "*"]
    // => (2 + 1) * 3 = 9
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    int result = solution.evalRPN(tokens);
    cout << "The result of the RPN expression is: " << result << endl;

    return 0;
}