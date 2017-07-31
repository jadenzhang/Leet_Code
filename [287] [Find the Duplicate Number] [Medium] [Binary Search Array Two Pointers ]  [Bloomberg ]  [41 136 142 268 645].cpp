/*
Question# + Difficulty + Topic + Company + Similar_Question
[287] [Find the Duplicate Number] [Medium] [Binary Search Array Two Pointers ] 
[Bloomberg ] 
[41 136 142 268 645].cpp
*/


/* O(nlogn) Binary Search Approach */
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = 1,high = nums.size()-1;
        while(low<high)
        {
            int mid = (low+high)/2;
            int count = 0;
            for(int i = 0;i<nums.size();i++) count+= nums[i]<=mid? 1:0;
            if(count>mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};

/* O(n) Two Pointer Approach */
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        //The "tortoise and hare" step.  
        //We start at the Beginning of the array because 0 is non-turning back(from 1-n)
        //if the integer is from 0 to n-1(contain n+1 item), 
        //then the non-turning back num is n because no value will lead to n
   
        int slow = 0,fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //meet in loop
        int finder = 0;
        while(finder!=slow)
        {
            finder = nums[finder];
            slow = nums[slow];
        }
        return slow;
    }
};
