//Question# + Difficulty + Topic + Company + Similar_Question
//[191] [Number of 1 Bits] [Easy] [Bit Manipulation] 
//[Microsoft Apple] 
//[190 231 338 401 461].cpp

/* C++*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            n &= n-1;
            count++;
        }
        return count;
    }
};

/* Tricks!

n &= n-1 will clear the Least Significant 1 bit
*/
