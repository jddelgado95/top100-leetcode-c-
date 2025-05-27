/*
https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/3sum/

https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

[-1,0,1,2,-1,4]
1. Sort the array to use a two pointer method
[-4,-1,-1,0,1,2]
2. Same logic of 2sum problem
*/

#include<vector>
#include<map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Sorts the input array. This helps avoid duplicates and allows the two-pointer approach.
        sort(nums.begin(), nums.end());
        //Stores the final result of triplets. i is used to iterate through the array.
        vector<vector<int>> triplets;
        int i = 0;
        while(i < nums.size()){
            //Avoid duplicates: only consider nums[i] if it's the first element or not the same as the previous.
            if(i == 0 || (i - 1 >= 0 && nums[i-1] != nums[i])){
                //Fix firstNo. The other two numbers must sum to -firstNo
                int firstNo = nums[i];
                int target = -firstNo;
                //use a helper function (twoSum) to find all pairs starting from index i+1 to end that sum to target
                vector<vector<int>> pairs = twoSum(nums, i + 1, nums.size() - 1, target);
                for(vector<int>& pair : pairs){
                    //Combine the current fixed number with each valid pair to form a triplet and store it.
                    vector<int> triplet;
                    triplet.push_back(firstNo);
                    triplet.push_back(pair[0]);
                    triplet.push_back(pair[1]);
                    triplets.push_back(triplet);
                }
            }
            //Move to the next fixed number.
            i++;           
        }
        return triplets;
    }

    vector<vector<int>>twoSum(vector<int>& nums, int start, int end, int target){
        //Two pointers f (front) and s (second) to search for pairs.
        int f = start, s = end;
        vector<vector<int>> pairs;
        //Standard two-pointer loop.
        while(f < s){
            // value already considered, so ignore it
            if(f - 1 >= start && nums[f - 1] == nums[f]){
                f++;
                continue;
            }
            //These prevent duplicate values from being reused in multiple pairs.
            // value already considered, so ignore it
            if(s + 1 <= end && nums[s+1] == nums[s]){
                s--;
                continue;
            }
            //move left pointer
            //Compare the sum with the target and move pointers accordingly.If a valid pair is found, store it and move f forward.
            if(nums[f] + nums[s] < target){ 
                f++;
            }
            else if(nums[f] + nums[s] > target){ 
                s--;
            } else {
                vector<int> pair;
                pair.push_back(nums[f]);
                pair.push_back(nums[s]);
                pairs.push_back(pair);
                f++;
            }

        }

        return pairs;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for(auto triplet : result) {
        cout << "[ ";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}