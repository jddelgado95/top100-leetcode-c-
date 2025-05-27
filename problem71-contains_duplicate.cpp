/*
https://leetcode.com/problems/contains-duplicate/
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/check-if-the-given-input-contains-duplicates/#expected-approach-by-using-unordered_set-data-structure-on-time-and-on-space

The main idea is to insert each value into a HashSet, which only stores unique elements. If any insertion fails or if any elements are already exits in HashSet, it means a duplicate exists, so return true. If all insertions succeed, it indicates that all elements are unique, so return false.
*/

#include <iostream>
#include <vector> 
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        //Count the freq of numbers
        for(int num : nums){
            //if the element is in the map, it means that the number has been seen before
            if(mp.find(num) == mp.end()){
                mp[num] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 1};

    cout << "Test case 1 (no duplicates): ";
    cout << (sol.containsDuplicate(nums1) ? "True" : "False") << endl;

    cout << "Test case 2 (has duplicates): ";
    cout << (sol.containsDuplicate(nums2) ? "True" : "False") << endl;

    return 0;
}