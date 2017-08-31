/*
Question# + Difficulty + Topic + Company + Similar_Question
[39] [Combination Sum] [Medium] [Array Backtracking  ] 
[Snapchat Uber] 
[17 40 77 216 254 377].cpp
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        recur(result,candidates,vector<int>(),target,0);
        return result;
    }
    
    void recur(vector<vector<int>> &result,vector<int> nums,vector<int> tmplist,int target,int pos)
    {
        if(target<0) return;//wrong combination
        else if(target==0) result.push_back(tmplist);//finish one
        else
        {
            for(int i =pos;i<nums.size();i++)
            {
                if(nums[i]>target) return;
                tmplist.push_back(nums[i]);
                recur(result,nums,tmplist,target-nums[i],i);//so pos means can use more than once
                tmplist.pop_back();// remove finished num
            }
        }
    }
};
