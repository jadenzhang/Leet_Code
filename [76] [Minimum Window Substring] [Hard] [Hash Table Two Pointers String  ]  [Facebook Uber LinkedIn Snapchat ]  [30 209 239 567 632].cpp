/*
Question# + Difficulty + Topic + Company + Similar_Question
[76] [Minimum Window Substring] [Hard] [Hash Table Two Pointers String  ] 
[Facebook Uber LinkedIn Snapchat ] 
[30 209 239 567 632].cpp
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        
        unordered_map<char,int> hash;
        /*Put required char in hash*/
        for(int i=0;i<t.size();i++)
        {
            if(hash.count(t[i]))hash[t[i]]++;
            else hash[t[i]]=1;
        }
        
        /*Go Through S*/
        int start = 0,length=0,total=0;
        for(int head = 0,tail=0;tail<s.size();tail++)
        {
            if(!hash.count(s[tail])) continue;//ignore and carry on
            
            hash[s[tail]]--;//mark as found, decrease count
            if(hash[s[tail]]>=0) total++;//increase couunt of how many char we marked
            
            if(total==t.size())//found one window
            {
                while(!hash.count(s[head])||hash[s[head]]<0)
                {
                    if(hash.count(s[head])) hash[s[head]]++;//remove mark and see if can mark later
                    head++;
                }
                if(!length|| (tail-head+1)<length)//update length
                {
                    length = tail-head+1;
                    start=head;
                }
            }
        }
        return s.substr(start,length);
    }
};
