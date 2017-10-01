/*
Question# + Difficulty + Topic + Company + Similar_Question
[46] [Permutations] [Medium] [Backtracking] 
[Microsoft LinkedIn ] 
[31 47 60 77].cpp
*/

class Solution {
public:
    
    void recur(vector<vector<int>>& res, vector<int> nums,int depth)
    {
        if(depth==nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i = depth;i<nums.size();i++)
        {
            swap(nums[depth],nums[i]);
            recur(res,nums,depth+1);
            // restore
            swap(nums[depth],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recur(res,nums,0);
        return res;
    }
};
