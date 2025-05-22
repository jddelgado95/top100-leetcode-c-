/*
https://leetcode.com/problems/climbing-stairs/
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
Solution approach: 
http://geeksforgeeks.org/count-ways-reach-nth-stair/

Using Recursion – O(2^n) Time and O(n) Space
We can easily identify the recursive nature of this problem. A person can reach nth stair either from (n-1)th stair or (n-2)th stair. Thus, for each stair n, we calculate the number of ways to reach the (n-1)th and (n-2)th stairs, and add them to get the total number of ways to reach the nth stair. This gives us the following recurrence relation:

countWays(n) = countWays(n-1) + countWays(n-2)

How many ways takes me to go from point i to point n?


*/

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> mp;
        return f(0, n, mp);
        
    }

    int f(int i, int n, unordered_map<int, int>& mp){
        //the map will store all the computed values
        //nothing to compute
        if( i> n){
            return 0;
        }
        //We are already at the end
        else if(i == n){
            return 1;
        }
        else {
            //if map contains the value that I need, then use it, if not, compute it and store it
            if(mp.find(i) != mp.end()){
                //Not found it, then store it
                return mp[i];
            } else {
                //compute the value
                int val = f(i+1, n, mp) + f(i+2, n, mp);
                //store the new computed value
                mp[i] = val;
                return val;
            }
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
        