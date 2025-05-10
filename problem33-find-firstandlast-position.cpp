/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/*
Solution approach
https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/    

the idea is to find the first and last occurrence of a given number separately using binary search. 

1. For the first occurrence of a number 
If (high >= low): Calculate  mid = low + (high – low)/2;
If ((mid == 0 || x > arr[mid-1]) && arr[mid] == x): return mid
Else if (x > arr[mid]): return first(arr, (mid + 1), high, x, n);
Else: return first(arr, low, (mid -1), x, n);
Otherwise: return -1;

2. For the last occurrence of a number 
if (high >= low): calculate mid = low + (high – low)/2;
if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x ): return mid;
else if(x < arr[mid]): return last(arr, low, (mid -1), x, n);
else: return last(arr, (mid + 1), high, x, n);
otherwise: return -1;
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //find the last (rightmost and leftmost) occurrences of target
        int left = findleft(nums, target);
        int right = findright(nums, target);
        //Creates a result vector with both values and returns it
        vector<int> result; 
        result.push_back(left);
        result.push_back(right);
        return result;
    }

    int findleft(vector<int>& arr, int target){
        int start = 0, end = arr.size() - 1;
        int ans = -1; // if im not able to find the answer, i have to return -1
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] < target){
                start = mid + 1; //go to the right side
            } else if (arr[mid] > target){
                end = mid - 1; //go to the left side
            } else { // index = target, If equal, store the index in ans, and keep searching for the first occurrence
            //We store the index (mid) as a potential answer. But since we're looking for the first occurrence, we continue searching to the left — so we update end = mid - 1.
                ans = mid;
                end = mid -1;
            }
        }
        return ans;
    }

    int findright(vector<int>& arr, int target){
        int start = 0, end = arr.size() - 1;
        int ans = -1; // if im not able to find the answer, i have to return -1
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] < target){ // target greater than mid 
                start = mid + 1; //go to the right side
            } else if (arr[mid] > target){ //target less than mid
                end = mid - 1; //go to the left side
            } else { // index = target, If equal, store the index in ans, and keep searching for the first occurrence
                ans = mid;
                start = mid  + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);

    cout << "Range of target " << target << ": ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}