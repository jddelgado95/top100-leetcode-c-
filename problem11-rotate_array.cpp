/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. 

Example 1: 
Input nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/

/*
Rotate = 3 times
1,2,3,4,5,6,7

1st rotation: 7,1,2,3,4,5,6
2nd rotation: 6,7,1,2,3,4,5
3rd rotation: 5,6,7,1,2,3,4 <== This is the answer
*/

/* Solution approach:

Two observations: 
If k(nums of iterations) is equal to the size of the array (n), the first and last rotation will have become the same array. And n+1 rotation will be the same as k-(k+1)

Lets say that k = 8, and n = 7. So 8 % 7 => 1

Step 1: Reverse the array
7,6,5,4,3,2,1
Step 2: Reverse the first k elements
5,6,7,4,3,2,1
Step 3: reverse the last remaining elements
5,6,7,1,2,3,4 <== Solution final

https://www.geeksforgeeks.org/print-array-after-it-is-right-rotated-k-times/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
        void rotate(vector<int>& nums, int k){
            int n = nums.size();
            k = k%n;
            reverse(nums, 0 , n-1); // Reverse the whole array
            reverse(nums, 0, k-1); // reverse the first K elements
            reverse(nums, k, n-1); // reverse the rest elements of the array
        }

        void reverse(vector<int>& nums, int start, int end){
            int i = start, j = end;
            while(i < j){
                int temp = nums[i]; // Stores first element in temp
                nums[i] = nums[j]; // Stores last element in first element
                nums[j] = temp; // Stores temp element, which is first element, in the last element
                i++; // Decrease the counting for both ends. 
                j--;
            }
        }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution sol;
    sol.rotate(nums, k);

    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}