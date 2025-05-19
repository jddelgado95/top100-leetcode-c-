/*
https://leetcode.com/problems/number-of-1-bits/
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

Use shift left and check using AND if it is set or not. 
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0; 
        for(int i=0; i <= 31; i++){
            if((n & (1 << i)) != 0){
                count++;
            }
        }
        return count;
    }
};


int main() {
    Solution sol;

    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int result = sol.hammingWeight(n);
    cout << "Hamming Weight (number of 1 bits): " << result << endl;

    return 0;
}