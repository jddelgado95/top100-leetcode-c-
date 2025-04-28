/*
Given a 1-indexed array of integers numbers that is already sorted in non decreasing order, find 2 numbers such that they add up to a specific target number. Let these 2 numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length. 
Return the indices of two numbers index1 and index2 added by one as an integer aray [index1, index2] of length 2. 
Constraints: 
Your solution must use only constant extra space. 
The tests are generated such that there is exactly one solution. You may not use the same element twice. 

Example 1: 
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: the sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1,2]
*/

/*
Solution approach: 
This is a two sum problem: https://www.geeksforgeeks.org/check-if-pair-with-given-sum-exists-in-array/

Here we are using the Sorting and Two-Pointer Technique, which basically is to use it, the array must be sorted. Once the array is sorted then we can use this approach by keeping one pointer at the beginning (left), callling it F and another at the end (right), calling it D, of the array. Then check the sum of the elements at these two pointers:
If the sum equals the target (F == D), we’ve found the pair.
If the sum is less than the target F + D < TARGET, move the left pointer to the right to increase the sum.
If the sum is greater than the target(F+D > TARGET), move the right pointer to the left to decrease the sum.

Another approach that may be interesting is: Sorting and Binary Search. 
We first sort the array. Then for each number arr[i] in the array, we first calculate its complement (i.e., target – current number) then uses binary search to quickly check if this complement exists in the subarray after index i. If we find the complement, we returns true; If we never find a complement (after checking all numbers), we return false.
*/

/*
Consider this: https://www.geeksforgeeks.org/2sum/
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public: 
        vector<int> TwoSum(vector<int>& input, int target){
            // Define the first pointer (f) and the last pointer (s)
            int f = 0, s = input.size() - 1;
            vector<int> result;
            while(f < s){
                int sum = input[f] + input[s];
                if(sum < target){
                    f++;
                }
                else if(sum > target){
                    s--;
                }
                else {
                // We are returning here the index + 1, because in the statement of the problem it says "Given a 1-indexed array".     
                    result.push_back(f + 1); 
                    result.push_back(s + 1);
                    break;
                }
            }
            return result;
        }
};

int main(){
    Solution sol;
    vector<int> input = {2,7,11,15};
    vector<int> result = sol.TwoSum(input, 9);
    // Remember that I can not cout a vector as if it was an integer. 
    cout << "The index result is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}