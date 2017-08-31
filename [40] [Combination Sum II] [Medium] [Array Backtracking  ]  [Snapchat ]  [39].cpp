/*
Question# + Difficulty + Topic + Company + Similar_Question
[40] [Combination Sum II] [Medium] [Array Backtracking  ] 
[Snapchat ] 
[39].cpp
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        recur(result,candidates,vector<int>(),target,0);
        return result;
    }
    
    void recur(vector<vector<int>> &result,vector<int> nums,vector<int> tmplist,int target,int pos)
    {
        if(target<0) return;//wrong combination, delete last
        else if(target==0) result.push_back(tmplist);//finish one
        else
        {
            for(int i =pos;i<nums.size();i++)
            {
                if(nums[i]>target) return;
                if(i > pos && nums[i] == nums[i-1]) continue; // skip duplicates
                tmplist.push_back(nums[i]);
                recur(result,nums,tmplist,target-nums[i],i+1);//so pos means can use only once
                tmplist.pop_back();// remove finished
            }
        }
    }
};
