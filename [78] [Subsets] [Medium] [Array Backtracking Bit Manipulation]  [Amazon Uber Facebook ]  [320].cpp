/*
Question# + Difficulty + Topic + Company + Similar_Question
[78] [Subsets] [Medium] [Array Backtracking Bit Manipulation] 
[Amazon Uber Facebook ] 
[320].cpp
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        
        recur(ans,nums,0,vector<int>{});
        return ans;
    }
    void recur(vector<vector<int>> &ans,vector<int> nums,int pos,vector<int> cur)
    {
        if(pos==nums.size())
        {
            ans.push_back(cur);
            return;
        }
        
        /* Skip */
        recur(ans,nums,pos+1,cur);
        
        /* Add */
        cur.push_back(nums[pos]);
        recur(ans,nums,pos+1,cur);
    }
};
