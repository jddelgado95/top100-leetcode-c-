/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/* solution approach:
We can sort in a linear way, since we are not allow to yse any library sort function. 
Start iterating over the array, from left to right
If we get a 2, move it to the right side, if we get a 0, move it to the left size, automatically the ones will be in the middle. 
With this we are going to create a partition in the array, we should use two pointers (right and left)
left pointer: position where i can shift a zero
right: position where I can shift a two. 

If we have 2,0,2,1,1,0]: 

left = 0
rifght = 5
Start iterating
if ARR[i] == 2
SWAP(ARR[i], ARR[right])
Move to the next, since we moved a 2 to the end, then move the right pointer: right--, right = 4 now
since ARR[left] = 0, move left to the next position, left++ and i++
arr[left] == 1, ignore, move i++
now, ARR[i] == 0, swap with left, and move left++
*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        void sortColors(vector<int>& nums){
            // Init pointers
            int left = 0, right = nums.size() - 1;
            int i = 0; // Init counter
            while (i <= right){
                if(nums[i] == 0){
                    int temp = nums[i];
                    nums[i] = nums[left];
                    nums[left] = temp;
                    i++;
                    left++; // move pointer to the right
                }
                else if(nums[i] == 2){
                    int temp = nums[i];
                    nums[i] = nums[right];
                    nums[right] = temp;
                    right--; //move pointer to the left
                }
                else { // if nums[i] == 1 or other number
                    i++;
                }
            }
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "Sorted array (Dutch National Flag order): ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}