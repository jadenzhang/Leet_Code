/*
Question# + Difficulty + Topic + Company + Similar_Question
[38] [Count and Say] [Easy] [String] 
[Facebook] 
[271].cpp
*/

class Solution {
public:
    string countAndSay(int n) {
        string str="1";
        if(n<2) return str;
        for(int i =2;i<=n;i++)
        {
            string str1="";
            int count = 1;
            char current = str[0];
            for(int j = 1;j<str.size();j++)
            {
                if(current!=str[j])
                {
                    //First append the count then number
                    str1+='0'+count;
                    str1+=current;
                    current = str[j];
                    count = 1;
                } 
                else
                {
                    count++;
                }
            }
            str1+='0'+count;
            str1+=current;
            str = str1;
        }
        return str;
    }
};
