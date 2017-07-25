/*
Question# + Difficulty + Topic + Company + Similar_Question
[219] [Contains Duplicate II] [Easy] [Array Hash Table ] 
[Palantir Airbnb ] 
[217 220].cpp
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i =0;i<nums.size();i++)
        {
            if(hash.count(nums[i]) && abs(i-hash[nums[i]])<=k) return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};
