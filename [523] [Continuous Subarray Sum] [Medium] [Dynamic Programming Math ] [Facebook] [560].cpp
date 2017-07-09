//Question# + Difficulty + Topic + Company + Similar_Question
//[523] [Continuous Subarray Sum] [Medium] [Dynamic Programming Math ] 
//[Facebook] 
//[560].cpp

/*C++*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        if(n<2)return false;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod =  k == 0 ? sum: sum%k;
            if(m.find(mod)!=m.end())
            {
                if(i>m[mod]+1){return true;}
            }
            else m[mod] = i; 
        }
        return false;
    }
};

/* Explanation

Similar to 560, we use the hashtable to keep track the Mod number, if we experience same mod during iteration, 
it means some K*J exist in our iteration

      xxxxxxxxxxxxxxxxxxxxxxxx      So, if we find that the pre-mod equal to Current Mod, it means there exist some K*J
      |-> Pre-mod <-||->K*j<-|
      |-> Current Mod      <-|
 */
