/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

/* Solution approach
Number of Subsets of an array of size n = 2 ^ n
https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/

The idea is to use backtracking to explore all possible choices one by one recursively. For each element, there two options, either include it into subset or exclude it. 

Initialize an empty list subset to store the current subset elements, and a 2D list res to store all subsets.
Recursively iterate through the array elements.
Include (add) the current element to subset and recursively call the function for the next index.
Exclude (remove) the current element from subset to backtrack, and recursively call the function for the next index.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> final_subsets;
    //Temporarily holds elements for the current subset during recursion.
    vector<int> current_subset;
    //nums is the array we want to find subsets of
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums); // Start recursion at index 0 
        return final_subsets;
    }

    // i: decides if i want to include or exclude that element
    void backtrack(int i, vector<int>& nums){
        if(i == nums.size()){
            // We've considered all elements, so store the current subset
            //If we've reached the end of the array, store the current_subset as a valid subset
            vector<int> answer;
            for(int i = 0; i < current_subset.size(); i++){
                answer.push_back(current_subset[i]);
            }
            final_subsets.push_back(answer);
        } else {
            // not including the current element
            backtrack(i+1, nums);
            current_subset.push_back(nums[i]);
            // including the current element
            backtrack(i+1, nums);
            current_subset.pop_back();
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Sample input
    vector<vector<int>> result = sol.subsets(nums);

    // Print all subsets
    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
