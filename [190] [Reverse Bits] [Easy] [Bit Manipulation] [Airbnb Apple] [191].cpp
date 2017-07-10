//Question# + Difficulty + Topic + Company + Similar_Question
//[190] [Reverse Bits] [Easy] [Bit Manipulation] 
//[Airbnb Apple] 
//[191].cpp


/* C++ */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newn=0;
        for(int i =0;i<32;i++)
        {
            newn |= ((n<<i)>>(31-i))&(1<<i);
        }
        return newn;
    }
};

/* abcdefg
   first move left then move right to make it reverse(two direction)
   then and setted bit to leave one only bit
   or operation set the bit
*/
