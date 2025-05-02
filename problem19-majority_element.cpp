/*
Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*
Solution approach:
Using Sorting – O(n log n) Time and O(1) Space
The idea is to sort the array so that similar elements are next to each other. Once sorted, go through the array and keep track of how many times each element appears. When you encounter a new element, check if the count of the previous element was more than half the total number of elements in the array. If it was, that element is the majority and should be returned. If no element meets this requirement, no majority element exists.

https://www.geeksforgeeks.org/majority-element/

Check this: https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/

Create two counters: 
Count = 
MayorCount = 
Point them to the first element of the array
Traverse the array [1,2,3,2,2,4,2]
MC = 1 (thius is the element)
Count = 1

move both:
MC = 2
count = 0 (since now we have a diff element rather than 1, the count resets to 0)

Move again:
count = 1 (for the 2)
but now MC = 3

So move again and reset count to 0
and now we see a two: 
MC = 2
count = 0

And now count again: count =1
move: 
MC is still 2
so count = 2

Check that: 
k = number of times that the element appears in the array
N = number of elements in the array

k/N >= 1/2

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
    //This function implements the Boyer-Moore Voting Algorithm to find the majority element — the element that appears more than ⌊n/2⌋ times in the array.
    //Imagine it as pairing off different numbers. Every time a number appears that’s not the current candidate, it cancels out a vote. The true majority element will survive all cancellations because it appears more than half the time.
        int majorityElement(vector<int>& nums){
            int mc = nums[0];
            int count = 1;
            for(int i=1; i< nums.size(); i++){
                //If the current element is equal to the current majority candidate, increase the count.
                if(nums[i] == mc){
                    count++;
                }
                //If the current element is not equal to the candidate: Decrease count
                else{
                    count--;
                    //If count reaches zero, we "vote out" the current candidate and pick the new one (nums[i]) as the majority candidate, resetting count to 1.
                    if(count ==0){
                        mc = nums[i];
                        count = 1;
                    }
                }
            }
            return mc;
        }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}

