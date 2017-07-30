/*
Question# + Difficulty + Topic + Company + Similar_Question
[268] [Missing Number] [Easy] [Array Math Bit Manipulation ] 
[Microsoft Bloomberg ] 
[41 136 287].cpp
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();//0-n missing one, So total size n and i will increased up to n-1
        for(int i =0;i<nums.size();i++)
        {
            result ^=nums[i];
            result ^=i;
        }
        return result;
    }
};
