/*
https://leetcode.com/problems/divide-two-integers/
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

*/

/*
https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
Solution approach: 
Using Bit Manipulation - O(log(a)) Time and O(1) Space
The idea is similar to the previous approach with the only difference that instead of subtracting one unit of divisor from the dividend, we can subtract multiple units of divisor at once until the dividend becomes smaller than divisor. 

This can be easily done by iterating on the bit position i = 30 to 0. For each bit position i, where (divisor << i) is less than dividend, set the ith bit of the quotient and subtract (divisor << i) from the dividend. After iterating over all the bits, return the quotient with the corresponding sign.
*/

#include <iostream>
#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        //Special case: INT_MIN / -1 causes overflow in 32-bit int, so return INT_MAX
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        //else if(dividend == INT_MIN  && divisor == +1){
        //    return INT_MIN;
        //}
        //Tracks the sign of the result: it's positive if both inputs have the same sign
        bool isPositive = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));
        //Converts to long to avoid overflow and takes abs() to work with positive values.
        long a = abs((long) dividend);
        long b = abs((long) divisor);

        int quotient = 0;
        //if both values are equal, the answer is ±1 based on the sign
        if(a == b){
            return isPositive ? 1 : -1;
        }
        //Left-shifts b until it exceeds a.This finds the largest power of 2 multiple of b that fits into a
        while(a >= b){
            int i = 0;
            while((b << i) <= a){
                i++;
            }
            //Add that multiple to the quotient.
            //Subtract it from a, and repeat.
            quotient += (1 << (i - 1));
            a -= (b << (i - 1));        
        }
        //Return the final quotient, with correct sign
        return isPositive ? quotient : -quotient;
    }
};


int main() {
    Solution sol;

    std::cout << "10 / 3 = " << sol.divide(10, 3) << std::endl;        // Should print 3
    std::cout << "-7 / -3 = " << sol.divide(-7, -3) << std::endl;      // Should print 2
    std::cout << "-10 / 2 = " << sol.divide(-10, 2) << std::endl;      // Should print -5
    std::cout << "INT_MIN / -1 = " << sol.divide(INT_MIN, -1) << std::endl; // Should print INT_MAX

    return 0;
}