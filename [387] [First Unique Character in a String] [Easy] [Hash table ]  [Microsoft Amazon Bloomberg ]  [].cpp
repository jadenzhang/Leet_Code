/*
Question# + Difficulty + Topic + Company + Similar_Question
[387] [First Unique Character in a String] [Easy] [Hash table ] 
[Microsoft Amazon Bloomberg ] 
[].cpp
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash;
        for(int i =0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        
        for(int i = 0;i<s.size();i++)
        {
            if(hash[s[i]]==1) return i;
        }
        return -1;
    }
};

/* For Large N, Do only one Traverse */
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for(int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for(auto &p : m) {
            if(p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};
