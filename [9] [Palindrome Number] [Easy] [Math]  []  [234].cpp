/*
Question# + Difficulty + Topic + Company + Similar_Question
[9] [Palindrome Number] [Easy] [Math] 
[] 
[234].cpp
*/


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        //only reversing half of x
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        //either even number or  with middle num
        return (x==sum)||(x==sum/10);
    }
};
