/*
Question# + Difficulty + Topic + Company + Similar_Question
[278] [First Bad Version] [Easy] [Binary Search ] 
[ Facebook] 
[34 35 374].cpp
*/


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1,high = n;
        if(n==0) return -1;
        
        while(low<high)
        {
            int mid = low + ( high - low ) / 2 ;// to avoid overflow when low and high both big
            /*
            mid is bad: target at left or mid
            mid is not bad: target at right
            */
            if(isBadVersion(mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
