/*
Question# + Difficulty + Topic + Company + Similar_Question
[139] [Word Break] [Medium]  [Dynamic Programming ] 
[Google Uber Facebook Amazon Yahoo Bloomberg Pocket Gems ] 
[140].cpp
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        for(int i =0;i<wordDict.size();i++) hash[wordDict[i]] = 1;
        bool dp[s.size()+1] = {1};
        
        /*  dp[0] is true for blank segment to be true
            The second for check back to see if 0 to i
            can be segmented by see if 0-j and j-i can 
            be segmented
            the second for loop use -- because it's more
            possible to find segmentation of short at back
            than start at beginning for a long word
        */
        for(int i  = 1; i<s.size()+1;i++)
        {
            for(int j = i-1 ; j >= 0; j--)//for(int j = 0;j<i;j++)
            {
                if(dp[j] && hash.count(s.substr(j,i-j))) dp[i] = true;
            }
        }
        return dp[s.size()];

    }
};
