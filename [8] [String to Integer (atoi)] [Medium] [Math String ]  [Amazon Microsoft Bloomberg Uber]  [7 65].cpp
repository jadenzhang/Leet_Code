/*
Question# + Difficulty + Topic + Company + Similar_Question
[8] [String to Integer (atoi)] [Medium] [Math String ] 
[Amazon Microsoft Bloomberg Uber] 
[7 65].cpp
*/

/* C++ MY Solution */
class Solution {
public:
    int myAtoi(string str) {
        //discard white space until first int(or return if invalid char)
        //cout<<str[2]<<".."<<str.size();
        string new_str;
        long new_int=0;
        int sign=0;
        for(int i =0;i<str.size();i++)
        {
            if(str[i]!=' ')
            {
                if(str[i]=='-'&&!sign) 
                {
                    sign = -1;
                    if(++i>=str.size()) return 0;
                }
                else if(str[i]=='+'&&!sign)
                {
                    sign = 1;
                    if(++i>=str.size()) return 0;
                }
                if(str[i]<'0' || str[i]>'9')  return 0;

                new_str= str.substr(i,str.size()); 
                break;
            }
        }
        for(int i =0;i<new_str.size();i++)
        {
            char ch=new_str[i];
            if(ch<'0'|| ch>'9') break;
            //cout<<ch<<endl;
            new_int *=10;
            new_int += (int)ch-'0';
            if(i>10)break;
        }
        if(sign==-1) new_int = -new_int;
        cout<<new_int<<"  "<<(new_int>INT_MAX)<<"  "<<(new_int<INT_MIN)<<endl;
        if(new_int>INT_MAX||new_int<INT_MIN) return sign==-1? INT_MIN:INT_MAX;
        //else if(new_int<INT_MIN) return INT_MIN;
        
        return (int)new_int;
    }
};


/* C++ concise Version */
class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)return 0 ;
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();)
        {
            i = str.find_first_not_of(' ');
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-')? -1 : 1;
            while('0'<= str[i] && str[i] <= '9') 
            {
                result = result*10 + (str[i++]-'0');
                if(result*indicator >= INT_MAX) return INT_MAX;
                if(result*indicator <= INT_MIN) return INT_MIN;                
            }
            return result*indicator;
        }
    }
};
