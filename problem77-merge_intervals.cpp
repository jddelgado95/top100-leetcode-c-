/*
https://leetcode.com/problems/merge-intervals/
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 
Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

/*
solution approach: 
https://www.geeksforgeeks.org/merging-intervals/

1. Sort the array based on the starting times and ending times
2. overlap the numbers\
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Sorting the array
        sort(intervals.begin(), intervals.end());
        //vector to store the result
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            //check current interval
            vector<int> currentInterval = intervals[i];
            //check last interval
            vector<int> lastInterval = answer[answer.size() - 1];
            //check merging
            //compare the “last interval we have in answer” (call it lastInterval) with the next sorted interval (currentInterval).
            if(lastInterval[1] >= currentInterval[0]) {
                /*
                f lastInterval[1] >= currentInterval[0], it means the end of lastInterval is at or beyond the start of currentInterval. They overlap or touch, so we combine them into a single interval whose start is lastInterval[0] and whose end is max(lastInterval[1], currentInterval[1]).
                */
                vector<int> newInterval = {lastInterval[0], max(lastInterval[1], currentInterval[1])};
                answer.pop_back();
                answer.push_back(newInterval);
            }
            //If intervals are not overlapping    
            else{
                answer.push_back(currentInterval);
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1:
    vector<vector<int>> intervals1 = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    // Expected merged result: [[1, 6], [8, 10], [15, 18]]

    // Example 2:
    vector<vector<int>> intervals2 = {
        {1, 4},
        {4, 5}
    };
    // Expected merged result: [[1, 5]] since [1,4] and [4,5] touch

    // Example 3: out-of-order input
    vector<vector<int>> intervals3 = {
        {5, 7},
        {1, 3},
        {2, 4},
        {6, 8}
    };
    // Expected merged result after sorting and merging: [[1,4], [5,8]]

    // Put them into a list so we can run the same code on each:
    vector<vector<vector<int>>> tests = {intervals1, intervals2, intervals3};

    for (int idx = 0; idx < tests.size(); idx++) {
        cout << "Test " << idx+1 << " input intervals:\n";
        for (auto &interval : tests[idx]) {
            cout << "[" << interval[0] << "," << interval[1] << "] ";
        }
        cout << "\n";

        vector<vector<int>> merged = sol.merge(tests[idx]);
        cout << "Merged intervals:\n";
        for (auto &interval : merged) {
            cout << "[" << interval[0] << "," << interval[1] << "] ";
        }
        cout << "\n\n";
    }

    return 0;
}