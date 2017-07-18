/*
Question# + Difficulty + Topic + Company + Similar_Question
[188] [Best Time to Buy and Sell Stock IV] [Hard]  Dynamic Programming ] 
[] 
[121 122 123 ].cpp
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<=1) return 0;
        if(k==0) return 0;
        if (k>prices.size()/2){ // simple case
            int ans = 0;
            for (int i=1; i<prices.size(); ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int buys[k+1],  sells[k+1]; /* Add one to array, so [0] never update and we generalize the formulae*/
        for(int i =0;i<k+1;i++)
        {
            buys[i] = INT_MIN; sells[i] = 0;
        }
        for(int i =0;i<prices.size();i++)
        {
            for(int j = 1;j<k+1;j++)
            {
                /*By starting at 1, we have buys[1] = max(buys[1],sells[1-1]-prices[i])
                    which is buys[1] = max(buys[1],-prices[i])*/
                buys[j] = max(buys[j], sells[j-1]-prices[i]);
                sells[j] = max(sells[j],buys[j]+prices[i]);
            }
        }
        return sells[k];
    }
};
