/*
Question# + Difficulty + Topic + Company + Similar_Question
[344] [Reverse String] [Easy] [Two Pointers String  ] 
[] 
[345 541].cpp
*/

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }
};
