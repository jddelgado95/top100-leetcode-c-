/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/

/*
Solution approach: 
https://www.geeksforgeeks.org/kth-largest-element-in-an-array/#expected-approach-using-priority-queueminheap-on-logk-time-and-ok-space

Uses a minheap => above all elements of the array, the smallest elements is at top

[3,2,1,5,6,4]

1- Min heap of the first 3 elements
2- After the first 3, insert the next one and pop the top. 
3- And repeat

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Creates a vector heap of size k.
        vector<int> heap(k);
        //Initializes the first k elements of heap with the first k elements of nums.
        for(int i = 0; i < k; i++) heap[i] = nums[i];
        //Turns the heap into a min-heap using greater<int>().
        //The smallest element will now be at the front (heap[0]
        make_heap(heap.begin(), heap.end(), greater<int>());
        //Iterates over the rest of the elements in nums, starting from index k.
        for(int i = k; i < nums.size(); i++){
            //If the current number is greater than or equal to the smallest in the heap (heap[0]
            if(nums[i] >= heap[0]){
                heap.push_back(nums[i]);
                //Add the number to the heap.
                //Reheapify to maintain min-heap property.
                push_heap(heap.begin(), heap.end(), greater<int>());
                pop_heap(heap.begin(), heap.end(),greater<int>());
                //Remove the smallest element (at the front) and maintain heap size k.
                heap.pop_back();
            }
        }
        //The root of the min-heap now holds the k-th largest element.
        return heap[0];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}