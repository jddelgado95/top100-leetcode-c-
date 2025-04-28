/* 
Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a diff day in the future to sell that stock. 
Return the max profit you can achieve from this transaction. If you cannot achieve any profit, return 0. 
Example 1: 
Input prices = [7,1,5,3,6,4]
Output = 5
Explanation = Buy on day 2 (prices = 1) and sell on day 5 (price = 6), profit = 6-1 => 5
Note that buying on day 2 and selling on day 1s not allowed because you must buy before you sell. 

Example 2: 
Input prices = [7,6,4,3,1]
Output = 0
Explanation = In this case, no transactions are done and the max profit = 0. 
*/

/*
Solution approach:
Look for the minimum price that I can buy in order to make the max profit. Then, traverse the array and subtract the minimum price with the index of the iteration in order to check what's the max profit.  


*/

#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public:
        int maxProfits(vector<int>& prices){
            int min_price = prices[0];
            int profit = 0;
            for(int i=1; i < prices.size(); i++){
                int currentProfit = prices[i] -  min_price;
                profit = max(profit, currentProfit);
                min_price = min(min_price, prices[i]);
            }
            return profit;
        }
};

int main(){
   Solution sol;
   //vector<int> input = {7,6,4,3,1};  
   vector<int> input = {7,1,5,3,6,4};
   int result = sol.maxProfits(input);
   cout << "The max profit is " << result << endl;
   return 0;
}