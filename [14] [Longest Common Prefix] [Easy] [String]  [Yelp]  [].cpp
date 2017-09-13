/*
Question# + Difficulty + Topic + Company + Similar_Question
[14] [Longest Common Prefix] [Easy] [String] 
[Yelp] 
[].cpp
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        // First start with first sting as prefix
        string prefix = strs[0];
        
        if(strs.size()==1) return prefix;
        
        for(int strpos = 0;strpos<prefix.length();strpos++)
        {
            for(int vecpos = 0; vecpos<strs.size();vecpos++)
            {
                // Condition 1: index should be less than the current string in the array
                // Condition 2: character at index should match with the character of the current string
                if( (strpos>strs[vecpos].length()-1) || (strs[vecpos][strpos]!=prefix[strpos]) )
                    return prefix.substr(0,strpos);
            }
        }
        return prefix;
    }
};

