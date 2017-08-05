/*
Question# + Difficulty + Topic + Company + Similar_Question
[263] [Ugly Number] [Easy] [Math] 
[] 
[202 204 264].cpp
*/


class Solution {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
        return num == 1;
    }
};
