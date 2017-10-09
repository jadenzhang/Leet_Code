/*
Question# + Difficulty + Topic + Company + Similar_Question
[242] [Valid Anagram] [Easy] [Hash Table Sort ] 
[Amazon Uber Yelp ] 
[49 266 438].cpp
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        if(s.size()!=t.size())return false;
        for(int i = 0;i<s.size();i++)
        {
            hash[s[i]]++;hash[t[i]]--;
        }
        
        for(auto i = hash.begin();i!=hash.end();i++)
        {
            if(i->second) return false;
        }
        return true;
    }
};
