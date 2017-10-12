/*
Question# + Difficulty + Topic + Company + Similar_Question
[384] [Shuffle an Array] [Medium] [] 
[] 
[].cpp
*/

class Solution {
    vector<int> num;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        num = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(num);
        for(int i = 0;i<nums.size();i++)
        {
            int pos = rand()%(nums.size()-i);
            swap(nums[i],nums[i+pos]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
