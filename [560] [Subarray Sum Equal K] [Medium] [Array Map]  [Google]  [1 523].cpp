/*
Question# + Difficulty + Topic + Company + Similar_Question
[560] [Subarray Sum Equal K] [Medium] [Array Map] 
[Google] 
[1 523].cpp
*/


/*C++ with hash table*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum]; 
        }
        return res;
    }
};

/* Hash table stores whether there exist sum-k presum in the map
e.g.
      xxxxxxxxxxxxxxxxxxxxxxxx  
      |-> Pre-sum <-||-> K <-|
      |-> Current Sum      <-|
      
      So if Pre-sum that equal to Current Sum - K, It means there exist sub-array that sum to K
      
      Initialized pair {0,1} is to handle sub-array start with beginning 0
*/
