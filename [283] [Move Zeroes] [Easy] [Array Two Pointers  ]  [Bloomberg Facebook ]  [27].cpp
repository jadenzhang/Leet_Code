/*
Question# + Difficulty + Topic + Company + Similar_Question
[283] [Move Zeroes] [Easy] [Array Two Pointers  ] 
[Bloomberg Facebook ] 
[27].cpp
*/

/* My Approach, Two PTR, Switching 0 and NON-0 elements */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = 0,tail = 0;
        while(nums[tail]&&tail<nums.size()){front++;tail++;}
        while(tail<nums.size())
        {
            while(!nums[tail])
            {
                tail++;
                if(tail==nums.size()) return;
            }
            nums[front]=nums[tail];
            nums[tail]=0;
            front++;tail++;
        }
    }
};

/* Another Approach, Move all non-zero one by one, then overwrite the tail to 0s */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
