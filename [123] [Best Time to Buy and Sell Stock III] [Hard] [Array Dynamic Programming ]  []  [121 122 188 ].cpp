/*
Question# + Difficulty + Topic + Company + Similar_Question
[123] [Best Time to Buy and Sell Stock III] [Hard] [Array Dynamic Programming ] 
[] 
[121 122 188 ].cpp
*/


/* My TLE Answer :(   with O(N^2) naive thinking*/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit = 0;
        for(int i =0;i<prices.size();i++)
        {
            vector<int> tmp (prices.begin(),prices.begin()+i), tmp1(prices.begin()+i,prices.end());
            int a = helper(tmp);int b = helper(tmp1);
            maxprofit = (a+b)>maxprofit? a+b: maxprofit;
            //cout<<"split at: "<<i<<"  maxprofit: "<<maxprofit<<endl;
        }
        return maxprofit;
    }
    
    int helper(vector<int>& prices) 
    {
        if(prices.size()<=1) return 0 ;
        int profit = 0, mini = INT_MAX;
        for(int i =0;i<prices.size();i++)
        {
            mini= min(prices[i],mini);
            profit = max(prices[i] - mini, profit);
        }
        return profit;
    }
};

