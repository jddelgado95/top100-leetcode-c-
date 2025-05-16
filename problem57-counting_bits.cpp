/*
http://leetcode.com/problems/counting-bits/
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

/*
solution approach: 
https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
iterate thorugh index 0 to index n and calculate the number of set bits. 
Use bitwise operators to, for instance: 
In the constraints of the problem, we know that 0 <= input n <= 10ˆ5 

So we know that the inpput will contain max 32bits, so manually check if the bit is set (1) or not set (0). 

iterate from 0 to 31, wether that bit is set or not. Use bitwise AND operator:
Use left shift: 

if(NUM & (1 << i) > 0 ) TRUE = ith bit is SET, else is NOT SET. 
5 & (1 << 3) (checking for third bit)
5 is 0101, shift 3 to the left makes it 10000 so (5 & 10000) should be FALSE, because five is 0101. 

But for bit 2: 
5 & (1 << 2) => TRUE, since 0101 & bit 2 is 0100. 
*/
#include <iostream>
#include<vector>

using namespace std; 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++){
            result.push_back(getNoOfSetBits(i));
        }
        return result; 
    }

    int getNoOfSetBits(int num) {
        int count = 0; // get the count of which bits are set
        for(int i = 0; i <= 31; i++){
            if((num& (1 << i)) > 0){
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Example input where every number appears twice except 4
    int test_input = 5;

    Solution solution;
    vector<int> result = solution.countBits(test_input);

    //vector<int> rightView = sol.rightSideView(root);

    // Printing the result
    cout << "Printing the result: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}