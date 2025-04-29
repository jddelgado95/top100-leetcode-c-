/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all elements of nums except nums[i].
The product of any prefix or suffic of nums is guaranted to fit in a 32-bit integer.
You must write an algorithm that runs in 0(n) time and without ysing the division operation.

Example 1: 
Input: nums = [1,2,3,4]
Output: [24, 12, 8, 6]
*/

/* Solution approach: 

i = (ARR[0] x ARR[1] x ... x ARR[i-1] x ARR[i+1] x ... x ARR[n-1])

The idea is to precompute the prefix and suffix products and store them in two arrays. Now we can find the product of array except i-th element, by using these precomputed arrays in constant time.

product of array except i-th element = prefProduct[i] * suffProduct[i]

https://www.geeksforgeeks.org/a-product-array-puzzle/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> ProductExpSelf(vector<int>& input){
        // Create two helper arrays will store the product of all elements to the left of input[i] and the the product of all elements to the right of input[i]
        vector<int> left(input.size(), 1); // 1 means the initial value of the vector. So it creates a vector of size input.size initialized with only 1s. 
        vector<int> right(input.size(), 1);
        // Compute the left array
        for(int i = 1; i < input.size(); i++){
            left[i] = left[i-1] * input[i-1];
        }

        cout << "The left vector is: ";
        for (int i = 0; i < left.size(); i++) {
            cout << left[i] << " ";
        }
        cout << endl;
        // Compute the right array
        for(int i = input.size()-2; i >= 0; i--){
            right[i] = right[i+1] * input[i+1];
        }

        cout << "The right vector is: ";
        for (int i = 0; i < right.size(); i++) {
            cout << right[i] << " ";
        }
        cout << endl;
        
        vector<int> output(input.size());
        // Compute the final array
        for(int i = 0; i < input.size(); i++){
            output[i] = right[i] * left[i];
        }
        return output;
    }
};

int main(){
    Solution sol;
    vector<int> input = {1,2,3,4};
    vector<int> answer = sol.ProductExpSelf(input);
    cout << "The index result is: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}