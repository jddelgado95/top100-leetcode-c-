/* 
Give an integer array nums, move all 0s to the end of it while maintaining the relative order of the non-zero elements.
Note: that you must do this in place without making a copy of the array. 

Example: 
Input nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

/* Solution approach: 
https://www.geeksforgeeks.org/move-zeroes-end-array/

MOve all the non-zero elements to the front. 
Create two pointers: START and i. 
Input nums = [0,1,0,3,12]
if ARR[i] == 0, then do nothing
Move i pointer
if ARR[i] /= 0, then swap ARR[i] with ARR[START]
Input nums = [1,0,0,3,12]
Move START pointer, START++ to meet the same position of i
Move i in otder to find the next non zero element
SWAP  ARR[i] with ARR[START] until you meet a non zero element
Input nums = [1,3,0,0,12]
And now repeat until is done
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public: 
        void moveZeroes(vector<int>& input){
            // Init the pointer start
            int start = 0;
            for(int i = 0; i < input.size(); i++){
                if(input[i] != 0){
                    //Swap logic
                    int temp = input[start];
                    input[start] = input[i];
                    input[i] = temp;
                    start++;
                }
            }
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original vector: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}