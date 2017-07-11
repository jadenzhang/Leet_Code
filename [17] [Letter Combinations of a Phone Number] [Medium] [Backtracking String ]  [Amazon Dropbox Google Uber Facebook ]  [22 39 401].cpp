/*
Question# + Difficulty + Topic + Company + Similar_Question
[17] [Letter Combinations of a Phone Number] [Medium] [Backtracking String ] 
[Amazon Dropbox Google Uber Facebook ] 
[22 39 401].cpp
*/


/* C++ */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.empty()) ans.push_back("");
        vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i =0; i<digits.size();i++)
        {
            string chars = phone[digits[i] - '0'];
            //cout<<chars<<endl;
            vector<string> tmp;
            for(int j = 0; j<ans.size();j++)
            {
                for(int k =0;k<chars.size();k++)
                {
                    tmp.push_back(ans[j]+chars[k]);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
