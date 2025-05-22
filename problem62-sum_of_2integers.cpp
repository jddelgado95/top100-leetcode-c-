/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
*/

#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        //Declares a variable to store the carry of the bitwise addition.Why unsigned int? Because we only need to store positive carry bits without sign extension
        unsigned int carry = 0;
        //The loop continues as long as there’s a non-zero carry in b
        while(b != 0) {
            //calculates the carry bits using bitwise AND:
            //a & b → gives the bits where both a and b have 1s — these are the positions that need to carry over.
            //static_cast ensures signed ints are safely treated as unsigned.
            //Shifts the carry bits left by 1. This aligns the carry to the correct bit position (just like how you'd carry to the next column in regular addition)
            carry = (static_cast<unsigned int >(a) & static_cast<unsigned int>(b)) << 1;
            //Bitwise XOR adds the two bits without carrying
            a = static_cast<unsigned int>(a) ^ static_cast<unsigned int>(b);
            b = carry;
        }
        return static_cast<int>(a);
    }
};


int main() {
    Solution sol;

    int a, b;

    // Example 1
    a = 5, b = 3;
    std::cout << "Sum of " << a << " and " << b << " is: " << sol.getSum(a, b) << std::endl;

    // Example 2
    a = -7, b = 4;
    std::cout << "Sum of " << a << " and " << b << " is: " << sol.getSum(a, b) << std::endl;

    // Example 3
    a = -10, b = -6;
    std::cout << "Sum of " << a << " and " << b << " is: " << sol.getSum(a, b) << std::endl;

    return 0;
}