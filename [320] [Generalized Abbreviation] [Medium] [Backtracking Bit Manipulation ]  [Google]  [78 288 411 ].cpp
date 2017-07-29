/*
Question# + Difficulty + Topic + Company + Similar_Question
[320] [Generalized Abbreviation] [Medium] [Backtracking Bit Manipulation ] 
[Google] 
[78 288 411 ].cpp
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        recur(ans, word, 0, 0, "");
        return ans;
    }
    void recur(vector<string> &ans,string word,int pos,int count,string current)
    {
        if(pos==word.size())
        {
            if(count) current+=to_string(count);
            ans.push_back(current);
            return ;
        }
        
        /* Abbr */
        recur(ans,word,pos+1,count+1,current);
        
        /* Copy Word */
        /* Reset count and add to current then add current char*/
        recur(ans,word,pos+1,0,current+(count?to_string(count):"")+word[pos]);
    }
    
};
