/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution {
public:
    int findMaxProfit(vector<int>&prices,bool f,int day,vector<vector<int>>&dp){
        if(day>=prices.size())return 0;
        if(dp[f][day]!=-1)return dp[f][day];
        if(!f){
            int x = findMaxProfit(prices,!f,day+1,dp) - prices[day];
            int y = findMaxProfit(prices,f,day+1,dp);
            return dp[f][day] = max(x,y);
        }
			int x  = prices[day] + findMaxProfit(prices,!f,day+2,dp);
			int y  = findMaxProfit(prices,f,day+1,dp);
        return dp[f][day] = max(x,y); 
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(2,vector<int>(prices.size(),-1));
        return findMaxProfit(prices,false,0,dp);
    }
};
