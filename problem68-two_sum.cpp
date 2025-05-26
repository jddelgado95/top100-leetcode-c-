/*

https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

/*
Solution approach:
Use a hash table to store the complement. 

input = [2,4,7,8,6,9] target=13

create an empty hastable to store the numbers as key and its index at value that we already checked in the vector
iterate through the input vector and compute the complement for each number, after computing the complement, checked for the number that you need to get the target in the hash table, if its not there, keep iterating and computing complements. 
*/

#include <vector>
#include <iostream>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //keep the numbers from the vector in key (its values) and value(its indexes). 
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            //compute the complement
            int complement = target - nums[i];
            //search for the complement in the HT and stores it in the HT if its not found within the HT
            if(mp.find(complement) != mp.end()){
                ans.push_back(mp[complement]);// index of the complement
                ans.push_back(i);               // index of the current number
                break;
            }
            //Stores the index of the vector as a key within the HT 
            mp[nums[i]] = i;
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}