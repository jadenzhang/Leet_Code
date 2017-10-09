/*
Question# + Difficulty + Topic + Company + Similar_Question
[168] [Excel Sheet Column Title] [Easy] [Math  ] 
[Facebook Microsoft Zenefits ] 
[171].cpp
*/

class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while(n>0)
        {
            str=(char)('A'+(--n)%26)+str;
            n/=26;
        }
        return str;
    }
};
