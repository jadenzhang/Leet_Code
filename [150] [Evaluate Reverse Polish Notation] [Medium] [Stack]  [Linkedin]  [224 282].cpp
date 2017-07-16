/*
Question# + Difficulty + Topic + Company + Similar_Question
[150] [Evaluate Reverse Polish Notation] [Medium] [Stack] 
[Linkedin] 
[224 282].cpp
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for (int i = 0;i<tokens.size();i++)
        {
            if(!tokens[i].compare("+"))
            {
                int b = sta.top();sta.pop();
                int a = sta.top();sta.pop();
                sta.push(a+b); 
            }
            else if(!tokens[i].compare("-"))
            {
                int b = sta.top();sta.pop();
                int a = sta.top();sta.pop();
                sta.push(a-b); 
            }
            else if(!tokens[i].compare("*"))
            {
                int b = sta.top();sta.pop();
                int a = sta.top();sta.pop();
                sta.push(a*b);
            }
            else if(!tokens[i].compare("/"))
            {
                int b = sta.top();sta.pop();
                int a = sta.top();sta.pop();
                sta.push(a/b); 
            }
            else sta.push(atoi(tokens[i].c_str()));
                    
        }
        return sta.top();
    }
};
