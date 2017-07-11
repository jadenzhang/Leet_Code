/*
Question# + Difficulty + Topic + Company + Similar_Question
[231] [Power of Two] [Easy] [Math Bit Manipulation ] 
[Google] 
[7 65].cpp
*/

/* MY C++ */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num1 = 0;
        if(n<0)return false;
        for(int i =0;i<31;i++)//ignore sign
        {
            if((n&(1<<i)))num1++;
        }
        return num1==1? true:false;
        
    }
};

//Check if only one bit is 1

/* C++ with n&(n-1) Trick*/
// n&(n-1) remove LSB of 1, so if only one bit is 1 it should be 0

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};
