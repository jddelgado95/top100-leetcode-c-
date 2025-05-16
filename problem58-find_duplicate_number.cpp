/*
https://leetcode.com/problems/find-the-duplicate-number/
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
*/

/*
Solution appraoch: 
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

Using binary search:
lets say we have: [1,2,3,3] n = 4

START = 1
END = n

We have X, so count the number of elements that are <= X
The idea is to count numbers and compare if it is great than each of them. So for example we have: 
x= 1
then x = 2, 2 > 1? TRUE 
then we have x = 3, 2 > 3 FALSE
then we have 3x = 3 again, 3 >= 3 TRUE. So the possibility of 3 being the duplicated is higher. 

We are going to use the middle number of the binary search to compare against the array elements. 

*/
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 1;
        int answer = 1;
        while(start <= end){
            int mid = (start + end)/2;
            int count = 0; 
            for (int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid){
                    count++;
                }
                if(count <= mid) {
                    start = mid + 1;
                } else {
                    answer = mid;
                    end = mid - 1;
                }

            }
        }
        return answer;
    }
};

int main() {
    // Example input: contains a duplicate number (3)
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution solution;
    int duplicate = solution.findDuplicate(nums);

    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}