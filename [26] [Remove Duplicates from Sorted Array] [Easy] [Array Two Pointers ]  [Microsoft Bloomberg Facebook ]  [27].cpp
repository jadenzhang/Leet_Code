/*
Question# + Difficulty + Topic + Company + Similar_Question
[26] [Remove Duplicates from Sorted Array] [Easy] [Array Two Pointers ] 
[Microsoft Bloomberg Facebook ] 
[27].cpp
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int count = 1,dupli = nums[0];
        for(int i =1,j=1;i<nums.size();i++)
        {
            if(nums[i]!=dupli)//non-duplicate
            {
                nums[j++] = nums[i];
                dupli = nums[i];
                count++;
            }
        }
        return count;
    }
};
