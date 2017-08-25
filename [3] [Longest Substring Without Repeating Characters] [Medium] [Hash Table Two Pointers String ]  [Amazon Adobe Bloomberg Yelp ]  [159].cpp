/*
Question# + Difficulty + Topic + Company + Similar_Question
[3] [Longest Substring Without Repeating Characters] [Medium] [Hash Table Two Pointers String ] 
[Amazon Adobe Bloomberg Yelp ] 
[159].cpp
*/

/*O(n) Two Pointers and Hash */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        unordered_map<char,int> hash;
        for(int i =0,j=0;i<s.size();i++)
        {
            if(hash.count(s[i]))//duplicate
            {
                j = max(j,hash[s[i]]+1);//move start ptr
            }

            hash[s[i]] = i;
            maxi = max(maxi,i-j+1);
        }
        
        return maxi;
    }
};


/* More Tricky Approach */
/* Use char 256 table as Hash */
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
