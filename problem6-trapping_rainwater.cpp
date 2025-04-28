/*
Given n non-negative integers representing an elevantion map where the width of each bar is 1, compute how much water it can trap after raining. 

Example 1: 
Input: heigth = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section is represetend by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
*/

/*
Solution approach: 
The trap water will be decide by the height of the elements to the left and to the right, for instance, 2,1,2, there, the max height is 2 at the left and 2 at the right, so in the middle, we can trap 1 of water. 
We can apply this formula: min(heighest point, second heighest point) - point where we want to estimate how much water we can trap, for intance in the array we should have: min(3,2) - 1 => 1. 
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public: 
        int TrapWater(vector<int>& height) {
            int n = height.size();
            // Init two vectors that will point to the beginning and end of the array
            vector<int> left(n);
            vector<int> right(n);
            left[0] = height[0]; // Beginning of vector
            right[n-1] = right[n-1]; // End of vector
            for(int i = 0; i < n; i++){
                left[i] = max(left[i-1], height[i]);
            }
            for(int i = n - 2; i>=0; i--){
                right[i] = max(right[i+1],height[i]);
            }
            int ans = 0;
            for(int i = 0; i<n; i++){
                // The quantity of trap water is delimited by the min of the two max of right and height
                ans += (min(left[i], right[i])-height[i]);
            }
        return ans;
        }
};

int main(){
    Solution sol;
    vector<int> input =  {0,1,0,2,1,0,1,3,2,1,2,1};
    int answer = sol.TrapWater(input);
    cout << " The result is " << answer << endl;
    return 0;
}

