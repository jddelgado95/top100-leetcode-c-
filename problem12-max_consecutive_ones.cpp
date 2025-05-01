/*
Give a binary array of nums, return the max number of consecutive 1s in the array
Example: 
Input => nums = [1,1,0,1,1,1];
Output: 3
Explanation: the first two digits or the last 3 digits are consecutive 1s. The max number of consecutive 1s is 3. 
*/

#include<vector>
#include<iostream>
using namespace std;
class Solution{
    public:
    int maxConsecutiveOnes(vector<int>& input){
        int count = 0;
        int ans = 0;
        for(int i=0; i<input.size();i++){
            if(input[i]==1){
                count++;
                if(count > ans){
                    ans = count;
                }               
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {1,1,0,1,1,1};
    int answer = sol.maxConsecutiveOnes(input);
    cout << "Answer is "<<answer<<endl;
    return 0;
}