/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

https://leetcode.com/problems/combination-sum/description/
*/

/*
Solution approach
Using backtracking
The idea is to use backtracking and recursively explore all possible combinations of elements, of the given array that sums up to given target value. If the remaining sum becomes less than 0 then backtrack to explore other possible combinations.

test case = candidates => [2,3,6,7] target = 7
create a function with these arguments: 
f(current index i, remaining target rem, combination found so far)

f(0, 7, []) // full target

The max times I can include a candidate is: target / candidate. So for instance, if I want to know how many times can I include the number 2: [7/2] => 3.5 = 4 times, which is [0 times, 1 times, 2 times, 3 times]

Including 2 0 times: 
f(1, 7, [])

Including number 2, 1 time: 
f(1, 5, [2])

2, 2 times: 
f(1, 3, [2,2])

3 times: 
f(1, 1, [2,2,2])


https://www.geeksforgeeks.org/combinational-sum/
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //Declares a 2D vector to store all valid combinations.
    vector<vector<int>> answer;  
    //This is the main function that receives input and returns the result.
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<int> combination;
        find_combinations(0, target, combination, candidates);
        return answer;
    }

    void find_combinations(int i, int remaining, vector<int>& combination, vector<int>& candidates){
        // We got to the size of the vector
        if (i == candidates.size()){
            if(remaining == 0){
                vector<int> final_combinations;
                // store combinations to the end array
                for(int i = 0; i < combination.size(); i++){
                    final_combinations.push_back(combination[i]);
                }
                answer.push_back(final_combinations);
            }
        } else {
            //Calculate how many times the current candidate can fit into the remaining target.
            int max_times = remaining/candidates[i];
            //Try using this candidate from 0 up to max_times
            for(int k = 0; k <= max_times; k++){
                //Copy the current remaining value.
                int newTarget = remaining;
                //Add the current candidate k times to the combination, and decrease the remaining accordingly
                for(int j = 0; j < k; j++){
                    combination.push_back(candidates[i]);
                    newTarget -= candidates[i];    
                }
                //Recur to the next candidate, passing the updated combination and target.
                find_combinations(i+1, newTarget, combination, candidates);
                //Backtrack: remove the k instances of the current candidate to explore other paths
                for(int j = 0; j<k; j++){
                    combination.pop_back();
                }
            }
        }
    }


};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Call the combinationSum function
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the result
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
