/*
Question# + Difficulty + Topic + Company + Similar_Question
[22] [Generate Parentheses] [Medium] [Backtracking String ] 
[Google Uber Zenefits ] 
[17 20].cpp
*/
/* C++ */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generator(ans,n,0,"");
        return ans;
    }
    
    void generator(vector<string> & ans,int left,int right,string str)
    {
        if((!left)&&(!right)) {ans.push_back(str);return;}
        if(left>0) generator(ans,left-1,right+1,str+"(");
        if(right>0) generator(ans,left,right-1,str+")");
        
    }
    
};

//keep track the left and right parenthesis, recursively search all possibility
