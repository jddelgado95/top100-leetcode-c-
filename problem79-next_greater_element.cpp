/*
https://leetcode.com/problems/next-greater-element-ii/
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/


/*
Solution approach:
https://www.geeksforgeeks.org/find-the-next-greater-element-in-a-circular-array/
We will create a stack where we store the positions 

Key Idea:
We use a monotonic decreasing stack (top of the stack is the index of the largest unresolved value). When a greater value appears, we resolve all smaller values from the stack.

*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack; //The stack holds indices of elements from nums that haven’t yet found their next greater number.
        vector<int> ans(nums.size(), - 1); //Initializes the result array with -1

        stack.push(0);
        
        for(int i = 1; i < nums.size(); i++){
            int current = nums[i];
            //Pop values from my stack where value is less than the current value
            //If nums[i] (current element) is greater than nums[stack.top()], then nums[i] is the next greater element for the number at index stack.top(). So we update the answer array:
            while(stack.size() > 0 && nums[stack.top()] < current){
                //We're assigning the next greater element for the index at the top of the stack.
                ans[stack.top()] = current;
                //And then pop the index from the stack (we're done with it).
                stack.pop();
            }
            //Push the current index i onto the stack.
            stack.push(i);
        }

        //Corner case: since we are using a circular array
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            //Pop values from my stack where value is less than the current value
            while(stack.size() > 0 && nums[stack.top()] < current){
                ans[stack.top()] = current;
                stack.pop();
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 1}; // Example input
    vector<int> result = solution.nextGreaterElements(nums);

    cout << "Next greater elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}