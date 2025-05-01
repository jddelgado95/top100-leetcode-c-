/*
You are given an integer height of length n. There are n vertical lines drawn sych that the two endpoints of the ith line are (i,0) and (i,height[i]). 
Find two lines that together with the x-axis form a container, such that the container contains the most water. 

Return the maximum amount of water a container can store. 
Note: you may not slant the container. 
*/

/*
Solution approach: 
https://www.geeksforgeeks.org/container-with-most-water/
[Expected Approach] Using Two Pointers – O(n) Time and O(1) Space
The idea is to maintain two pointers: left pointer at the beginning of the array and right pointer at the end of the array. These pointers act as the container’s sides so we can calculate the amount of water stored between them using the formula: min(arr[left], arr[right]) * (right – left). 


After calculating the amount of water for the given sides, we can have three cases:


arr[left] < arr[right]: This means that we have calculated the water stored for the container of height arr[left], so increment left by 1.
arr[left] >= arr[right]: This means that we have calculated the water stored for the container of height arr[right], so decrement right by 1.
Repeat the above process till left is less than right keeping track of the maximum water stored as the result.


Why are we moving the pointer which is pointing to the shorter line?

We are moving the pointer pointing to the shorter line to potentially find a taller line and increase the container’s height. Moving the pointer to the taller line would only reduce the width, but the height cannot increase because of the shorter line, thus decreasing the amount of water.

The algorithm shoukd look like this: 
nums = [1,8,6,2,5,4,8,3,7]
left = 0
right = 8
area = min(arr[left], arr[right]) * (right - left)
left++
left = 1
area = min(8,7) * 8 - 1 => 49
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int maxArea(vector<int>& height){
            int left = 0;
            int right = height.size() - 1;
            int ans = 0;

            while(left < right){
                int heightOfContainer = min(height[left],height[right]);
                int widthofContainer = right - left;
                int area = heightOfContainer*widthofContainer;
                if(area > ans){
                    ans = area;
                }
                // Here we are going to move according which one is less
                if(height[left] < height[right]){
                    left++;
                }
                else {
                    right--;
                }
            }
            return ans;
        }
};

int main(){
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int result = sol.maxArea(heights);
    cout << "The maximum area of water the container can store is: " << result << endl;
    return 0;
}