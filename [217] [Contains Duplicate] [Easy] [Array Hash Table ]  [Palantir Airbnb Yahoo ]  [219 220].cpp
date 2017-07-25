/*
Question# + Difficulty + Topic + Company + Similar_Question
[217] [Contains Duplicate] [Easy] [Array Hash Table ] 
[Palantir Airbnb Yahoo ] 
[219 220].cpp
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i =0;i<nums.size();i++) 
        {
            if(hash.count(nums[i])) return true;
            hash[nums[i]] = 1;
        }
        return false;
        
    }
};
