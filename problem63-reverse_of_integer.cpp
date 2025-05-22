/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 

Constraints:
-231 <= x <= 231 - 1
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/

This idea for this approach is to repeatedly extract the last digit of n using the modulus operator (n % 10) and appending it to the reverse number (revNum). After extracting the digit, the number n is reduced by dividing it by 10 (n = n / 10). This process continues until n becomes 0. Finally, the reversed number (revNum) is returned.
*/

#include <iostream>
#include <climits>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        /*
        Special edge case: INT_MIN is -2,147,483,648
        abs(INT_MIN) causes undefined behavior because its positive counterpart doesn't fit in a signed 32-bit int.
        So we return 0 early for safety.
        */
        if(x == INT_MIN){
            return 0;
        }
        //reversedNum: stores the final reversed number.
        int reversedNum = 0;
        //sign: captures if the number is negative.
        int sign = x < 0 ? -1 : 1;
        //x = abs(x): we reverse the positive value and reapply the sign at the end.
        x = abs(x);

        //Loop until all digits are reversed.
        while(x != 0){
            //Extracts the last digit (e.g. for 123 → gets 3).
            //% is the modulus operator, which returns the remainder of division.
            //Any integer % 10 gives the last digit.
            //x = 123;
            //digit = 123 % 10;  // ➞ 3
            int digit = x%10;
            //Safety check to prevent overflow:
            //If reversedNum * 10 + digit would overflow INT_MAX, we return 0.
            //Why INT_MAX / 10? Because if reversedNum is greater than 214748364, then multiplying by 10 will definitely exceed INT_MAX = 2,147,483,647.
            //If reversedNum is large enough, multiplying by 10 and adding another digit could exceed INT_MAX, which would cause undefined behavior or incorrect results
            if(reversedNum <= INT_MAX/10){
                /*
                Shift existing digits left and add the new digit.
                Remove the last digit from x.
                In decimal, multiplying by 10 moves digits one place to the left.

                For example, 42 → 420 makes space to add a new digit.
                Example:
                Suppose:
                x = 123;
                1st iteration:
                digit = 3
                reversedNum = 0 * 10 + 3 = 3

                2nd iteration:
                Next digit = 2
                reversedNum = 3 * 10 + 2 = 32

                3rd iteration:
                digit = 1
                reversedNum = 32 * 10 + 1 = 321
                Now the number is fully reversed! */

                reversedNum = reversedNum*10 + digit;
                //In integer division, dividing by 10 drops the last digit.
                //x = 123; x = 123 / 10 = 12;
                x = x/10;
            } else {
                //If overflow risk is detected, return 0 immediately.
                return 0;
            }
        }
        //Restore the original sign to the reversed number.
        return reversedNum*sign;
    }
};


int main() {
    Solution sol;

    // Test cases
    int x1 = 123;
    int x2 = -456;
    int x3 = 1534236469; // This should return 0 (overflow)
    int x4 = INT_MIN;

    std::cout << "Reversed " << x1 << " = " << sol.reverse(x1) << std::endl;
    std::cout << "Reversed " << x2 << " = " << sol.reverse(x2) << std::endl;
    std::cout << "Reversed " << x3 << " = " << sol.reverse(x3) << std::endl;
    std::cout << "Reversed " << x4 << " = " << sol.reverse(x4) << std::endl;

    return 0;
}