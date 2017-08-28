
/*
Question# + Difficulty + Topic + Company + Similar_Question
[238] [Product of Array Except Self] [Medium] [Array] 
[Amazon LinkedIn Apple Facebook Microsoft ] 
[42 152 265].cpp
*/


/* IDEA */
/*
  {              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
  { a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result (n,1);
        int forward = 1;
        int backward = 1;
        for(int i =1;i<n;i++)
        {
            forward*=nums[i-1];
            result[i]*=forward;
        }
        
        for(int i =n-2;i>=0;i--)
        {
            backward*=nums[i+1];
            result[i]*=backward;
        }
        return result;
    }
};
