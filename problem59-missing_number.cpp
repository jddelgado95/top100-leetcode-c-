/*
https://leetcode.com/problems/missing-number/
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/find-the-missing-number/

Using XOR Operation - O(n) Time and O(1) Space
 XOR of a number with itself is 0 i.e. x ^ x = 0 and the given array arr[] has numbers in range [1, n]. This means that the result of XOR of first n natural numbers with the XOR of all the array elements will be the missing number. To do so, calculate XOR of first n natural numbers and XOR of all the array arr[] elements, and then our result will be the XOR of both the resultant values.

 Property: 
 a ^ a = 0

 Lets say we have n = 4
 0 xor 1 xor 2 xor 3 xor 4 = x
 Now use the input og array: [2,1,4,0]
 2 xor 1 xor 4 xor 0 = y

 x ^ y = ans => with this will be cancelling xors (becoming zero), only left 3. 
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i <= nums.size(); i++){
            x = x^i;
        }

        int y = 0;
        for(int i = 0; i < nums.size(); i++){
            y = y^nums[i];
        }
        return x^y;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};  // Missing number is 2
    Solution solution;
    int missing = solution.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}