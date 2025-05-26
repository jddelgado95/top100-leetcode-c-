/*
https://leetcode.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

/*
Solution approach: 
https://www.geeksforgeeks.org/longest-consecutive-subsequence/
O(n) Time and O(n) Space
The idea is to use Hashing. We first insert all elements in a Hash Set. Then, traverse over all the elements and check if the current element can be a starting element of a consecutive subsequence. If it is then start from X and keep on removing elements X + 1, X + 2 .... to find a consecutive subsequence.

To check if the current element, say X can be a starting element, check if (X - 1) is present in the set. If (X - 1) is present in the set, then X cannot be starting of a consecutive subsequence.

For instance:
[50,48,45,44,47,49,51]

50 -> ignored because 49 exists
48 -> ignored because 47 exists
45 -> Ignored because 44 exists
44 -> Since 43 doest exist, we can start a sequence from 44
45 => exists, count = 2
46 doesnt exist, sequence stops here
ans = 2. 

Now do it for the next number in the array which is, 47, since 46 does not exists, start a sequence from 47, count = 1
48 exists, count 2
49 exists, count 3, 
50 exists, count 4
51 exists, count 5
52 does not exists, sequence stops here
ans = 5
49 since 48 exists, ignored it. 
51 -> ignored, since 50 exists. 

DONE. 
*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set; 
        //Build a set from the input array for O(1) average-time lookups.
        //Duplicates are automatically ignored (set property).
        for(int num: nums) {
            set.insert(num);
        }

        int ans = 0;
        for(int num: nums){
            //We only start counting a sequence from a number num if num - 1 is not in the set.
            //This ensures we only start from the beginning of a sequence.
            //For example: If num = 100 and num - 1 = 99 is not in the set, then 100 is the start of a sequence.
            if(set.find(num - 1) == set.end()){
                int currentNum = num;
                int currentStreak = 1;
                //Count how many consecutive numbers follow num.
                //For example: if num = 100, and 101, 102, and 103 exist in the set, the loop runs until no more consecutive numbers are found.
                while(set.find(currentNum + 1) != set.end()){
                    currentStreak++;
                    currentNum++;
                }
                //Update the maximum length found.
                if(currentStreak > ans){
                    ans = currentStreak;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test input
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Call the method and print the result
    int result = sol.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}