/*
Question# + Difficulty + Topic + Company + Similar_Question
[49] [Group Anagrams] [Medium] [Hash Table String ] 
[Facebook Amazon Bloomberg Uber Yelp ] 
[242 249].cpp
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> hash;
        for(int i = 0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            hash[tmp].push_back(strs[i]); 
        }
        
        for(auto item = hash.begin();item!=hash.end();item++)
        {
            res.push_back(item->second);
        }
        return res;
    }
};
