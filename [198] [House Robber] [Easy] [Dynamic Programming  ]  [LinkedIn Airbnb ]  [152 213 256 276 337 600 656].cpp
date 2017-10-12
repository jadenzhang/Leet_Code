/*
Question# + Difficulty + Topic + Company + Similar_Question
[198] [House Robber] [Easy] [Dynamic Programming  ] 
[LinkedIn Airbnb ] 
[152 213 256 276 337 600 656].cpp
*/
/* Can be simplify to Two Variable instead of N, just need to record last two val*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int max = 0,cur = 0;
        bool flag =0;
        vector<int> dp;
        dp.push_back(0);//0 for 0 house
        for(int i=0;i<nums.size();i++)
        {
            if(flag)
            {
                if(dp[i-1]+nums[i]> dp[i])//use previous and current, not rob last one  H H(R) H-> H(R) H H(R)
                {
                    dp.push_back(dp[i-1]+nums[i]);
                    flag = 1;
                }
                else 
                {
                    dp.push_back(dp[i]);
                    flag = 0;
                }
            }
            else
            {
                dp.push_back(dp[i]+nums[i]);//no flag: last house not robbed
                flag = 1;
            }
            
        }
        return dp[nums.size()];
    }
};
