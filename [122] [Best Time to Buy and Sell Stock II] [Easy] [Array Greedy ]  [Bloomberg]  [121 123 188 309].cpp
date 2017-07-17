/*
Question# + Difficulty + Topic + Company + Similar_Question
[122] [Best Time to Buy and Sell Stock II] [Easy] [Array Greedy ] 
[Bloomberg] 
[121 123 188 309].cpp
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        for(int i =1;i<prices.size();i++)
        {
            profit+= (prices[i]-prices[i-1])>0? prices[i]-prices[i-1]:0;
        }
        return profit;
    }

};
