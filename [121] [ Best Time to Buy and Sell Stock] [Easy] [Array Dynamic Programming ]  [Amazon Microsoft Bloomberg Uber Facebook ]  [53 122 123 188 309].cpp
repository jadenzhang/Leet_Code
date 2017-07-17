/*
Question# + Difficulty + Topic + Company + Similar_Question
[121] [ Best Time to Buy and Sell Stock] [Easy] [Array Dynamic Programming ] 
[Amazon Microsoft Bloomberg Uber Facebook ] 
[53 122 123 188 309].cpp
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, mini = INT_MAX;
        for(int i =0;i<prices.size();i++)
        {
            mini= min(prices[i],mini);
            profit = max(prices[i] - mini, profit);
        }
        return profit;
    }
};
