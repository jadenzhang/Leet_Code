/*
Question# + Difficulty + Topic + Company + Similar_Question
[10] [ Regular Expression Matching] [Hard] [Dynamic Programming Backtracking String  ] 
[Google Uber Airbnb Facebook Twitter  ] 
[44].cpp
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        /*
           a   b   c   d   e
        a  
        
        b
        
        c
        
        d
        
        e
        
        This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
        
        */
       // cout<<s.length()<<" "<<p.length()<<endl<<endl;
        bool dp [s.length()+1][p.length()+1];
        for(int i =0;i<=s.length();i++)
        {
            for(int j =0;j<=p.length();j++) dp[i][j] = 0;
        }

        dp[0][0] = true;
        
        /*initialization done*/
        
        
       /* for(int i = 0;i<p.length();i++)
        {
            for(int j =0;j<s.length();j++)
            {
                cout<<dp[j][i]<<"  ";
            }
            cout<<endl;
        }*/
        for (int i = 0; i <= s.length(); i++)
            for (int j = 1; j <= p.length(); j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[s.length()][p.length()];
    }
};
