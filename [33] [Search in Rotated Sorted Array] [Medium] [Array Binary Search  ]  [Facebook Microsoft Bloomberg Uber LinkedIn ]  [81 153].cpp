/*
Question# + Difficulty + Topic + Company + Similar_Question
[33] [Search in Rotated Sorted Array] [Medium] [Array Binary Search  ] 
[Facebook Microsoft Bloomberg Uber LinkedIn ] 
[81 153].cpp
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        if(low>high) return-1;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            
            if(nums[low]<=nums[mid])
            {
                if(target<nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            else
            {
                if(target>nums[mid])
                {
                   low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }
        return nums[low]==target?low:-1;
        
    }
};
