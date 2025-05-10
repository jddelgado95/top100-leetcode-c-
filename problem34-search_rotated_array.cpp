/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

The idea is based on the fact that in a sorted and rotated array, if we go to mid, then either the left half would be sorted or the right half (both can also be sorted). For example, arr[] = [5, 6, 0, 1, 2, 3, 4], mid = 3 and we can see that the subarray from mid + 1 to high is sorted. And in [5, 6, 7, 8, 9, 3, 4], we can see that the subarray from low to mid-1 is sorted. We can check which half is sorted by comparing arr[low] and arr[mid] (We could also compare arr[high] and arr[mid]). 


Find the mid point. If key is same as the mid, return the mid.
Find which half is sorted. If the key lies in the sorted half, move to that half. Otherwise move to the other half.
Note that once we find which half is sorted, we can easily check if the key lies here by checking if key lies in the range from smallest to largest in this half.


MID         |       TARGET
ORIGINAL    |      ROTATED     MOVE LEFT
ROTATED     |      ORIGINAL    MOVE RIGHT
ORIGINAL    |      ROTATED     Apply standard Binary Search
ROTATED    |      ROTATED     Apply standard Binary Search

How do we know if we are in an original or rotated part? 
TARGET >= ARR[0] => target existss in the rotated part
ARR[MID] >= ARR[0] => target existss in the rotated part


*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0, end = nums.size() - 1;

        while(start <= end){
            int mid = (start + end)/2;
            //mid in original region, target in rotated region
            if(nums[mid] >= nums[0] && target < nums[0]){ 
                //If the midpoint is in the left/original sorted region (because it's ≥ first element), and the target is in the right/rotated region (target < first element), then move start right 
                start = mid + 1; 
            //mid in rotated region, target in original region    
            } else if(nums[mid] < nums[0] && target >= nums[0] ){ 
                //If the midpoint is in the right/rotated region (because it's < first element), and the target is in the left/original region (target ≥ first), move end left
                end = mid - 1;
            } else { //Both mid and target are in the same region. If mid and target are in the same sorted region, proceed with regular binary search
                if(nums[mid] < target){ //If nums[mid] < target: search right
                    start = mid + 1;
                } else if(nums[mid] > target){ //If nums[mid] > target: search left
                    end = mid - 1;
                } else { //If nums[mid] == target: set answer and exit.
                    ans = mid;
                    break;
                }
            }
        }
        return ans;        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 1;

    int index = sol.search(nums, target);
    if(index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}