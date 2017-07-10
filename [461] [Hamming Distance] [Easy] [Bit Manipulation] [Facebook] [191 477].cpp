//Question# + Difficulty + Topic + Company + Similar_Question
//[461] [Hamming Distance] [Easy] [Bit Manipulation] 
//[Facebook] 
//[191 477].cpp

/* C++ */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^y;
        int count=0;
        while (diff)
        {
            diff &= diff-1;
            count++;
        }
        return count;
        
    }
};
