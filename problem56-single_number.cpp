/*

https://leetcode.com/problems/single-number/
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

/*
Solution approach
To avoid the naive solution of traversing all the array, store the numbers in and count, use bit manipulation

bitwise XOR: 
a xor b = 0
a xor 0 = a
a xor b = b xor a

We dont know which number is comming twice, we only know that one number is single. 
Let's say we have [2,1,4,1,2]
Apply: 2 xor 1 xor 4 xor 1 xor 2, so all of they will be cancelled under the first rule (a xor a = 0), except 4. 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            ans = ans^num; 
        }
        return ans;
    }
};

int main() {
    // Example input where every number appears twice except 4
    vector<int> nums = {2, 3, 2, 4, 3};

    Solution solution;
    int result = solution.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}