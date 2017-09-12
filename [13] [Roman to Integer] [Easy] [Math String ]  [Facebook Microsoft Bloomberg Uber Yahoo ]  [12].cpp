/*
Question# + Difficulty + Topic + Company + Similar_Question
[13] [Roman to Integer] [Easy] [Math String ] 
[Facebook Microsoft Bloomberg Uber Yahoo ] 
[12].cpp
*/



class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> hash = {{'I',1},{'V',5},
                                         {'X',10},{'L',50},
                                         {'C',100},{'D',500},
                                         {'M',1000}};
        int sum = hash[s[s.length()-1]];//start from back so we don't need to check if it has next char
        for(int i =s.length()-2;i>=0;i--)
        {
            if(hash[s[i]]<hash[s[i+1]])//Special - case
            {
                sum-=hash[s[i]];
            }
            else
            {
                sum+=hash[s[i]];
            }
        }
        return sum;
    }
};
