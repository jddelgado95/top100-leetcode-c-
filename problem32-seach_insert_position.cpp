/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
*/

/*
The idea is to use binary search, instead of scanning the entire array linearly. The thought process begins by recognizing that a sorted array allows us to use binary search, which reduces time complexity from O(n) to O(log n). 


We use two pointers (left and right) to narrow down the search space by comparing k with the middle element, halving the problem at each step. 
If k is found, return its index; otherwise, the left pointer will naturally point to the correct insertion position when the search ends.

https://www.geeksforgeeks.org/search-insert-position-of-k-in-a-sorted-array/

The idea is to place two pointers, one for the START of the ARRAY, and the other one at teh END of the ARRAY. 
since is it a sorted list, we can use binary search, we can split the list by: 
[1,2,4,6,7,9,12,19]
TARGET = 17

START = 0
END = 7
MID = (0+7)/2 => 3
ARR[MID] < TARGET 
3 < 7 => TRUE

So: 
START => MID + 1 => 4
END = 7
MID = (4+7)/2 => 5
5 < 7 => TRUE

So: 
START => 6
END => 7
MID = 7

AND SO ON

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int middle = (start + end)/2;
            if(nums[middle] < target){
                // moves the start pointer if the target is greater than middle
                start = middle + 1;
            } else {
                // moves the end pointer if the target is less than middle
                ans = middle;
                end = middle - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index = solution.searchInsert(nums, target);
    cout << "Target " << target << " should be at index: " << index << endl;

    return 0;
}