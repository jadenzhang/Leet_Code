/*
Question# + Difficulty + Topic + Company + Similar_Question
[127] [Word Ladder] [Medium] [] 
[Facebook Amazon LinkedIn Snapchat Yelp] 
[].cpp
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        if(beginWord==endWord) return res;
        unordered_map<string,bool> hash;
        for(int i =0;i<wordList.size();i++) hash[wordList[i]]=1;
        hash[beginWord]=1;
        if(!hash.count(endWord))return res;
        
        queue<string> frontier;
        successor(hash,frontier,beginWord);
        res = 2;//INCLUDE START END
        
        while(!frontier.empty())
        {
            int n = frontier.size();
            for(int i=0;i<n;i++)//This loop ensure we can count depth
            {
                string cur = frontier.front();
                frontier.pop();
                if(cur==endWord) return res;
                successor(hash,frontier,cur);
            }
            res++;            
        }
        return 0;
    }
    void successor(unordered_map<string,bool>& hash,queue<string>& frontier,string word)
    {
        hash.erase(word);//avoid cycle
        for(int i =0;i<word.size();i++)
        {
            char replace = word[i];
            for(int val = 0;val<26;val++)
            {
                word[i] = 'a'+val;
                if(hash.count(word))
                {
                    frontier.push(word);
                    hash.erase(word);//delete before explore to avoid repeated check in same depth
                }
            }
            word[i] = replace;//restore
        }
    }
};
