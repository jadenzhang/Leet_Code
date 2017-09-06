/*
Question# + Difficulty + Topic + Company + Similar_Question
[75] [Sort Colors] [Medium] [Array Two Pointers Sort ] 
[Pocket Gems Microsoft Facebook ] 
[148 280 324].cpp
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // |<---- i ------j ------k ->|
        //   red    white    blue
        int i = 0,j = 0;
        for(int k = 0; k<nums.size();k++)
        {
            int tmp = nums[k];
            nums[k] = 2;
            if(tmp<2) nums[j++] = 1;
            if(tmp==0) nums[i++] = 0;
        }
    }
};
