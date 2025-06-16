/*
https://leetcode.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

/*Solution approach:
https://www.geeksforgeeks.org/dsa/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    //a: stores all elements like a normal stack. 
    //b: keeps track of current minimums.
    stack<int> a,b;
    //Constructor for the class (currently does nothing, but could be used to initialize members if needed)
    MinStack() {
    }
    
    void push(int val) {
        //Pushes the value val into the main stack a
        a.push(val);
        //Push to be is the value that I'm inserting is less than or equal to whatever is at top or if its the first value that I'm inserting. 
        //Checks if b is empty or if val is less than or equal to the current min. If so, val is also pushed to b, updating the min-tracking stack.
        if(b.size() == 0 || val <= b.top()){
            b.push(val);
        }
    }
    
    //Removes the top of stack a.
    //If the value removed was also the current minimum (a.top() == b.top()), it's also popped from b.
    void pop() {
        if(a.size() >= 1){
            if(a.top() == b.top()){
                b.pop();
            }
            a.pop();
        }
    }
    
    int top() {
        return a.top();
    }
    //Returns the top of stack b, which is the current minimum element.
    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    cout << "Current min: " << s.getMin() << endl; // 3

    s.pop();
    cout << "After popping 7, top: " << s.top() << endl; // 3
    cout << "Current min: " << s.getMin() << endl;       // 3

    s.pop();
    cout << "After popping 3, top: " << s.top() << endl; // 5
    cout << "Current min: " << s.getMin() << endl;       // 5

    return 0;
}