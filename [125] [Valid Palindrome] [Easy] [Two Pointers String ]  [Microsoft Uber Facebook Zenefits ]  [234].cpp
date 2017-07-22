/*
Question# + Difficulty + Topic + Company + Similar_Question
[125] [Valid Palindrome] [Easy] [Two Pointers String ] 
[Microsoft Uber Facebook Zenefits ] 
[234].cpp
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start<end)
        {
            if(!isalnum(s[start])) start++;//ignore
            else if(!isalnum(s[end])) end--;//ignore
            else if(tolower(s[start])!=tolower(s[end])) return false;
            else 
            {
                start++; end--;
            }
        }
        return true;
    }
};
