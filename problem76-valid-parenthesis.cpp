/*
https://leetcode.com/problems/valid-parentheses/description/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/#expected-approach-1-using-stack-on-time-and-on-space

Step-by-step approach:

Declare a character stack (say temp).
Now traverse the string s. 
If the current character is an opening bracket ( '(' or '{'  or '[' ) then push it to stack.
If the current character is a closing bracket ( ')' or '}' or ']' ) and the closing bracket matches with the opening bracket at the top of stack, then pop the opening bracket. Else s is not balanced.
After complete traversal, if some starting brackets are left in the stack then the expression is not balanced, else balanced.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(isOpening(ch)) {
                st.push(ch);
            } else {
                if(st.size() == 0) {
                    return false;
                } else {
                    /*
                    In C++, std::stack::pop() does not return the element it removes—it only removes the top element. To both read and remove the top element, you must:
                    Call top() to get (peek) the element.
                    Call pop() to remove it.
                    */
                    char och = st.top();
                    st.pop();
                    if(!isMatching(och, ch)) return false;
                }
            }
        }
        if(st.size() > 0){
            return false;
        }
        return true;
    }

    //helper function to check if the bracket is an opening
    bool isOpening(char ch){
        return (ch == '(' || ch == '{' || ch == '[');
    }
    //helper function that checks is the brackets are completed
    //och => opening channel, cch => closing channel
    bool isMatching(char och, char cch) {
        return (och == '(' && cch == ')') || (och == '[' && cch == ']') || (och == '{' && cch == '}');  
    }
};



int main() {
    Solution sol;

    // A few test cases to validate bracket strings:
    std::string tests[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "",          // empty string → should be valid
        "(((())))",  // nested brackets
        "(((())",    // unbalanced
        "]",         // closing without opening
    };

    for (const auto& str : tests) {
        bool result = sol.isValid(str);
        std::cout << "isValid(\"" << str << "\") → "
                  << (result ? "true" : "false") << "\n";
    }

    return 0;
}