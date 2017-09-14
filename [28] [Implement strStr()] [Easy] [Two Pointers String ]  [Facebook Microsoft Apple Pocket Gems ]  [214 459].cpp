/*
Question# + Difficulty + Topic + Company + Similar_Question
[28] [Implement strStr()] [Easy] [Two Pointers String ] 
[Facebook Microsoft Apple Pocket Gems ] 
[214 459].cpp
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h1 = haystack.size(), h2 = needle.size();
        cout<<h1<<" "<<h2<<endl;
        if(!h2) return 0;
        if(!h1 || h1<h2) return -1;
        
        for(int i = 0;i<h1-h2+1;i++)
        {
            if(haystack[i]==needle[0])//first match
            {
                int j =1;
                for(;j<h2;j++)
                {
                    if(haystack[i+j]!=needle[j]) break;
                }
                if(j==h2) return i;
            }
        }
        
        return -1;
    }
};
