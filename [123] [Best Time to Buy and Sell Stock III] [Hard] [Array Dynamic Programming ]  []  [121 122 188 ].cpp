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


/* Much Better O(N) Space O(1) Solution, inspired by the 121 problem */
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int i=0; i<prices.size(); i++) { // Assume we only have 0 money at first

            hold1    = max(hold1,    -prices[i]);          // The maximum if we've just buy  1st stock so far. 

            release1 = max(release1, hold1+prices[i]);     // The maximum if we've just sold 1nd stock so far.

            hold2    = max(hold2,    release1-prices[i]);  // The maximum if we've just buy  2nd stock so far.

            release2 = max(release2, hold2+prices[i]);     // The maximum if we've just sold 2nd stock so far.
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
};
