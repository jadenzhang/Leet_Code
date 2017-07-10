//Question# + Difficulty + Topic + Company + Similar_Question
//[477] [Total Hamming Distance] [Medium] [Bit Manipulation] 
//[Facebook] 
//[461].cpp

/* C++ my slow version O(32n)*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(),dis=0;
        int zeros[32]={0} ,ones[32]={0};
        if(n<2) return 0;
        for(int j = 0;j<32;j++ )
        {
            for(int i = 0;i<n;i++)
            {
                if((nums[i]&(1<<j))>>j) ones[j]++;
                else zeros[j]++;
            }
            dis+= zeros[j]*ones[j];
        }  
        return dis;      
    }
};
// the Hamming distance in nth bit of vector of nums is P*Q( P is # with nth bit 0, Q is # with nth bit 1)


/* Faster Approach */
/*In each loop, we need to visit all numbers in nums to calculate how many numbers has 0 (or 1) as LSB.

If the biggest number in nums[] is K, the total number of loop is [logM] + 1.

So, the total time complexity of this approach is O(n).
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }
    }
};
