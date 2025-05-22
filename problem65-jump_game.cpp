/*
https://leetcode.com/problems/jump-game/
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/



*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //maxReachable is the farthest index you can reach so far.
        //Initially, from position 0, you can jump up to nums[0] steps.
        int maxReachable = nums[0];
        int i = 1;
        //You haven't finished scanning the array && You can still reach index i from previous jumps (maxReachable >= i)
        while (i < nums.size() && maxReachable >= i){
            /*
                At index i, if you can jump farther than maxReachable, then update it.
                i + nums[i] = how far you can go from index i
                This allows you to greedily track the furthest index you can reach at any point
            */
            if(i + nums[i] > maxReachable){
                maxReachable = i + nums[i];                
            }
            i++;
        }
        /*
        Finally, if you can reach or pass the last index, return true.
        Otherwise, return false.
        */
        if(maxReachable >= nums.size() - 1){
            return true;
        } else {
            return false;
        }
    }
};


int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {2, 3, 1, 1, 4};  // Should return true
    vector<int> nums2 = {3, 2, 1, 0, 4};  // Should return false

    cout << "Can jump (nums1): " << (sol.canJump(nums1) ? "True" : "False") << endl;
    cout << "Can jump (nums2): " << (sol.canJump(nums2) ? "True" : "False") << endl;

    return 0;
}