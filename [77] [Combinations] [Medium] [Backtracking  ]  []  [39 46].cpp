/*
Question# + Difficulty + Topic + Company + Similar_Question
[77] [Combinations] [Medium] [Backtracking  ] 
[] 
[39 46].cpp
*/


class Solution {
public:
    void recur(vector<vector<int>>& res,vector<int> num,int depth,int k,int n)
    {
        if(num.size()==k)
        {
            res.push_back(num);
            return;
        }
        
        for(int i=depth;i<n;i++)
        {
            num.push_back(i+1);//1...n so add 1 to 0-based
            recur(res,num,i+1,k,n);
            num.pop_back();//restore
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> num;
        recur(res,num,0,k,n);
        return res;
    }
};
