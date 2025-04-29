/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product. 
The test cases are generated so that the answer will fit in a 32-bit integer. 
A subarray is a contiguous subsequence of the array. 

Examnple 1: 
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product (6)
*/

/*
Solution approach: 
The approach is that the problem has to be solved by using a suffix or prefix array, which mean we are going to forwardly traverse the array, or do it backwards. But the subarray will not be in the middle of the array. For instance, if we have : [2,3,-2,4]. The subarray could be: 
[2,3]
[3,-2,4]
[-2,4]
[2,3,-2]

But never: 
[3,-2]

The answer will be alweays be prefix or sufix or the array. Why? 
Let's say that we can divide the array in three sections: x, y, and z. Which x is the beginning of the array, y the middle, and z the end of the array. 
If we study all the scenarios, which means when every section of the array can be either positive or negative, we will see that we will always need the beginning or the ending of the array to make the maximum possible product array. 
https://www.geeksforgeeks.org/maximum-product-subarray/

If we get a zero in the array, we will discard the prodcut so far, and start counting back, before getting the zero. 
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public: 
    int maxProduct(vector<int>& nums){
        int ans = 0;
        if (nums.size() == 1){
            return nums[0];
        }
        // This approach is for traversing forward 
        int currentProduct = 1;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] != 0){
                currentProduct =   currentProduct * nums[i];
                if(currentProduct > ans){
                    ans = currentProduct;
                }
                else{
                    currentProduct = 1;
                }
            }
        }
        // This approach is for traversing backwards 
        currentProduct = 1;
        for(int i=nums.size()-1; i >= nums.size(); i--){
            if(nums[i] != 0){
                currentProduct =   currentProduct * nums[i];
                if(currentProduct > ans){
                    ans = currentProduct;
                }
                else{
                    currentProduct = 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {2,3,-2,4};
    int answer = sol.maxProduct(input);
    cout <<"The answer is " << answer << endl;
    return 0;
}