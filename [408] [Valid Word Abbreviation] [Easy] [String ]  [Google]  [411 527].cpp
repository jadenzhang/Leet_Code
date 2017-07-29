/*
Question# + Difficulty + Topic + Company + Similar_Question
[408] [Valid Word Abbreviation] [Easy] [String ] 
[Google] 
[411 527].cpp
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j =0;
        for(int i =0;i<abbr.size();i++,j++)
        {
            cout<<"cur: "<<abbr[i]<<" j at: "<<word[j]<<endl;
            if(isdigit(abbr[i]))
            {
                int cnt =0;
                if(abbr[i]=='0')return false;
                while(i<abbr.size() && isdigit(abbr[i]))
                {
                    cnt = cnt*10+abbr[i++]-'0';
                }
                j+=cnt-1;
                i--;
            }
            else if(j>=word.size()||abbr[i]!=word[j]) return false;
        }
        if(j!=word.size()) return false;
        return true;
    }
};
