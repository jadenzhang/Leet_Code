/*
Question# + Difficulty + Topic + Company + Similar_Question
[171] [Excel Sheet Column Number] [Easy] [Math] 
[Microsoft Uber ] 
[168].cpp
*/

class Solution {
public:
    int titleToNumber(string s) {
        int index = 0;
        for(int i = 0;i<s.size();i++)
        {
            index = index*26+(int)(s[i]-'A'+1);
        }
        return index;
    }
};
