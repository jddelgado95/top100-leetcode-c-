/* 
You're given an array of integer nums, there is a sliding window of sixe k which is moving from the very left of the arrayto the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. 
Return the max sliding window

Example 1: 
Input: nums = [1,3,-1,-3,5,3,,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 

Window position                    Max
----------------------         ------------
[1 3 -1] -3 5 3 6 7                3
1 [3 -1 -3] 5 3 6 7                3
1 3 [-1 -3 5] 3 6 7                5
1 3 -1 [-3 5 3] 6 7                5
1 3 -1 -3 [5 3 6] 7                6
1 3 -1 -3 5 [3 6 7]                7
*/

/*
Useful theory:
Using double ended queue (dequeue), in order to use useful elements. 
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
Step-by-Step Algorithm:

Create a deque to store only useful elements of current window.
Run a loop and insert the first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Now, run a loop from k to the end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.

https://www.geeksforgeeks.org/deque-in-python/

*/

/* Solution approach:
An element becomes useless under two conditions: 
If is not a part of the current window. 
Window ends at j, with a total size of k. So the starting position of the window is: j - (k + 1). So if an element is less than j - k + 1, is useless. 
For this case we need to pop from left side of the window. 

if a high value element is found on the right side of it. 
For this case we need to pop from right side of the window.

So we have [1,3,-1,-3,5,3,,6,7], k = 3. 
We are going to work with indexes. So, first, add the index 0 to the new array (its value is 1 in the array above). 
By the second approach, value of index 0 is less than value in the index 1, then pop out the index 0 and add index 1.
Add the second index, its value is less than the value of index 1, so dont make changes. 
By the index 3, we get to the end of the window, so compute the formula j - k + 1 => 3 - 3 + 1 => 1. 
SO, compare against the left indexes, is there an index less than 1? No.  
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution{
    public:
    vector<int> MaxSlidingWindow(vector<int>& nums, int k){
        vector<int> answers;
        deque<int> de;
        de.push_back(0);
        // Pop useless elements, the ones that not belong to the window and elements that are smaller than the current element
        for(int i = 1; i<k; i++){
            while(de.size()>0 && nums[de.back()] < nums[i]){
                de.pop_back();
            }
            de.push_back(i);
        }
        answers.push_back(nums[de.front()]);

        for(int j = k; j < nums.size(); j++){
            int startingPoint = j - k + 1;
            while(de.size() > 0 && de.front() < startingPoint){
                de.pop_front();
            }
            while(de.size() > 0 && nums[de.back()] < nums[j]){
                de.pop_back();
            }
            de.push_back(j);
            answers.push_back(nums[de.front()]);
        }
        return answers;
    }
};

int main(){
    Solution sol;
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    vector<int> answer = sol.MaxSlidingWindow(input, 3);
    cout << "The index result is: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}