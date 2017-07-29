/*
Question# + Difficulty + Topic + Company + Similar_Question
[320] [Generalized Abbreviation] [Medium] [Backtracking Bit Manipulation ] 
[Google] 
[78 288 411 ].cpp
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        dfs(result, word, 0, 0, "");
        return result;
    }
    
    void dfs(vector<string>& result, string word, int pos, int count, string cur) {
        if(pos == word.size()) {
            if(count > 0)   cur += to_string(count);
            result.push_back(cur);
            return;
        }
        /** add the current word **/
        dfs(result, word, pos + 1, 0, cur + (count? to_string(count):"") + word[pos]);

        /** skip the current word **/
        dfs(result, word, pos + 1, count+1, cur);
        
    }
};
