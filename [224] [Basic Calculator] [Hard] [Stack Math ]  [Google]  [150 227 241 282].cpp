/*
Question# + Difficulty + Topic + Company + Similar_Question
[224] [Basic Calculator] [Hard] [Stack Math ] 
[Google] 
[150 227 241 282].cpp
*/


/* My messy Version*/
class Solution {
public:
    int calculate(string s) {
        stack<long> sta;
        int ans = 0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                long num = 0;
                while(s[i]<='9'&&s[i]>='0')
                {
                    num*=10;
                    num+=(int)(s[i]-'0');
                    i++;
                }
                i--;
                sta.push(num);
            }
            else if(s[i]=='-') sta.push(LONG_MIN);
            else if(s[i]=='(') sta.push(LONG_MAX);
            else if(s[i]==')')
            {
                int subsum = 0;
                while(sta.top()!=LONG_MAX)
                {
                    int num = sta.top();
                    sta.pop();
                    if(sta.top()==LONG_MIN)
                    {
                        num = -num;
                        sta.pop();
                    }
                    subsum+=num;
                }
                sta.pop();
                sta.push(subsum);
            }
            if(i==s.size()-1)
            {
                while(!sta.empty())
                {
                    int num = sta.top();
                    sta.pop();
                    if(!sta.empty()&&sta.top()==LONG_MIN)
                    {
                        num = -num;
                        sta.pop();
                    }
                    ans+=num;
                }
            }
        }
        return ans;
    }
};

/* more concise sol */
class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};

