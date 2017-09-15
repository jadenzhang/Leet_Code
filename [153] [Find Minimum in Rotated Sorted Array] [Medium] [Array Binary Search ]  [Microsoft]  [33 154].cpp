/*
Question# + Difficulty + Topic + Company + Similar_Question
[153] [Find Minimum in Rotated Sorted Array] [Medium] [Array Binary Search ] 
[Microsoft] 
[33 154].cpp
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //same as rotated find element
        // We separate sorted part and chaos part
        int low = 0, high = nums.size()-1;
        while(low<high)
        {
            if(nums[low]<nums[high])//sorted
                return nums[low];
            int mid = (low+high)/2;
            if(nums[mid]>=nums[low])
            {
                //sorted,rotation after mid
                low=mid+1;
            }
            else high = mid;
        }
        
        return nums[low];
    }
};
