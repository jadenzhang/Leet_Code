
/*
Question# + Difficulty + Topic + Company + Similar_Question
[20] [Valid Parentheses] [Easy] [Stack String ] 
[Google Airbnb Facebook Twitter Zenefits Amazon Microsoft Bloomberg ] 
[22 32 301].cpp
*/

/* C++ */
class Solution {
public:
    bool isValid(string s) {
        stack <char> paren;
        for(int i =0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(':   paren.push(s[i]);break;
                    
                case ')':   if( paren.empty()||paren.top()!='(')return false;
                            else{paren.pop();break;}
                    
                case '[':   paren.push(s[i]);break;
                    
                case ']':   if(paren.empty()|| paren.top()!='[' )return false;
                            else{paren.pop();break;}
                    
                case '{':   paren.push(s[i]);break;
                    
                case '}':   if( paren.empty()||paren.top()!='{' )return false;
                            else{paren.pop();break;}
            }
        }
        return paren.empty()? true:false;
    }
};
