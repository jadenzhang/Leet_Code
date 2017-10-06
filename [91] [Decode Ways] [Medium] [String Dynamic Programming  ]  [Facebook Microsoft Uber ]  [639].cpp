/*
Question# + Difficulty + Topic + Company + Similar_Question
[91] [Decode Ways] [Medium] [String Dynamic Programming  ] 
[Facebook Microsoft Uber ] 
[639].cpp
*/

class Solution {
public:
    int numDecodings(string s) {
        if(!s.size()) return 0;
        
        int n = s.size();
        int dp[n+1] = {1};
        dp[1] = s[0]=='0'? 0:1;//it might start with illegal char
        
        for(int i =2;i<=n;i++)
        {
            int one = (int)(s[i-1]-'0');
            int two = ((int)(s[i-2]-'0'))*10+one;
            
            if(one>=1&&one<=9) dp[i]+=dp[i-1];
            if(two>=10&&two<=26)dp[i]+=dp[i-2];
            
        }
        return dp[n];
    }
};
