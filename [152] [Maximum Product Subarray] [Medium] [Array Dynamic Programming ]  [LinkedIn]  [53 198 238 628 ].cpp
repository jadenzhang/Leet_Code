/*
Question# + Difficulty + Topic + Company + Similar_Question
[152] [Maximum Product Subarray] [Medium] [Array Dynamic Programming ] 
[LinkedIn] 
[53 198 238 628 ].cpp
*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1,mini =1,ans = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
        {
            int tmp = maxi;
            maxi = max(nums[i],max(maxi*nums[i], mini*nums[i]));
            mini = min(nums[i],min(tmp*nums[i],mini*nums[i]));
            ans = max(ans, maxi);
        }
        return ans;
    }
};
