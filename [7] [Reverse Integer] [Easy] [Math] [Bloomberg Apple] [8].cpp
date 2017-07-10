//Question# + Difficulty + Topic + Company + Similar_Question
//[7] [Reverse Integer] [Easy] [Math] 
//[Bloomberg Apple] 
//[8].cpp


/* C++ */
class Solution {
public:
    int reverse(int x) {
    long reversedNum = 0;

    long input_long = x;

    while (input_long)
    {
        reversedNum = reversedNum * 10 + input_long % 10;
        input_long = input_long / 10;
    }

    return (reversedNum<INT_MIN || reversedNum>INT_MAX) ? 0 : reversedNum;
    }
};
