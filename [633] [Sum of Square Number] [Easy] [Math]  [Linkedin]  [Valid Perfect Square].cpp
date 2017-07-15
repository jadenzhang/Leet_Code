/*
Question# + Difficulty + Topic + Company + Similar_Question
[633] [Sum of Square Number] [Easy] [Math] 
[Linkedin] 
[Valid Perfect Square].cpp
*/

class Solution {
public:
bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        
        while(a <= b){
            
            if(a*a + b*b == c)return true;
            else if(a*a + b*b > c)b--;
            else a++;
        }
        return false;
    }
};
