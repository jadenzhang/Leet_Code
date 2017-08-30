/*
Question# + Difficulty + Topic + Company + Similar_Question
[27] [Remove Element] [Easy] [Array Two Pointers ] 
[] 
[26 203 283].cpp
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        for(int i =0,j=0;i<nums.size();i++)
        {
            if(nums[i]==val)continue;
            else
            {
                nums[j++] = nums[i];
                length++;
            }
        }
        return length;
    }
};
