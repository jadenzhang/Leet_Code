/*
Question# + Difficulty + Topic + Company + Similar_Question
[412] [Fizz Buzz] [Easy] [ ] 
[] 
[].cpp
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i =1;i<=n;i++)
        {
            string str = "";
            if(i%3 && i%5) str+=to_string(i);
            else if(!(i%3)) str+="Fizz";
            if(!(i%5)) str+="Buzz";
            ans.push_back(str);
        }
        return ans;
    }
};
