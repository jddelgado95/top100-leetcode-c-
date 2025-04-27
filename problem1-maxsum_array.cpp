/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum

Example 1: 
Input nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation = [4,-1,2,1] has the largest sum = 6

Subarray means a contiguous part of an array
*/

/*
Solution: 
- Create two variables, one to store the current sum, and the other one to store the maximum sum so far.  
So the idea is to point the current sum to the first element, and update the max sum so far variable with it, next, sum the current sum number with the next one in the array. Check if the max sum so far is greater than the current sum, if not, update it with the current sum. Continue iterating within the array, and sum with the next element, update the max sum so far, and so on. 
If the max sum so far becomes negative, start with the next positive number in the array and update the max sum so far with it. For instance, if the max sum so far is -2, then move to the next positive in the array which is 1 in the position [1].
*/

/*
Kadane's Algorithm: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/ 
*/

/*
To run it (on Mac): 
    $ g++ -std=c++11 problem1-maxsum_array.cpp -o problem1
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public:
    /* vector<int>& nums: dynamic array of integers (like a list of numbers).
    (&):it is passed by reference, function will not make a copy of nums, but instead will use the original array. This is faster and more memory-efficient, especially for big arrays.
    A vector is like a dynamic array — it can grow or shrink in size automatically. It’s part of the Standard Template Library (STL), so it comes with helpful features like easy indexing (nums[i]), size checking (nums.size()), and no need to manually manage memory (unlike normal arrays).
     */
        int maxSubArray(vector<int>& nums) {
            int maxSoFar = nums[0];
            int currentSum = nums[0];

            for(int i=1; i<nums.size(); i++){
                if(currentSum < 0){ // If currentSum is negative, then discard it
                    currentSum = 0;
                }
                currentSum = currentSum + nums[i]; //Move the current sum to the next element of the list. 
                if(currentSum > maxSoFar){
                    maxSoFar = currentSum;
                }                
            }
            return maxSoFar;

    }
};

// Main function
int main() {
    Solution sol; // Create an object of the Solution class
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    int result = sol.maxSubArray(nums); // Call the method on the object

    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}