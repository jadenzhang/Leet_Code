/*
Question# + Difficulty + Topic + Company + Similar_Question
[55] [Jump Game] [Medium] [Array Greedy ] 
[Microsoft ] 
[].cpp
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy approach: Record the maximum index we can reach
        int record=0;
        for(int i  = 0;i<nums.size();i++)
        {
            if(i>record) return false;
            record = max(record,nums[i]+i);
        }
        return true;
    }
};
