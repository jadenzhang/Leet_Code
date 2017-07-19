/*
Question# + Difficulty + Topic + Company + Similar_Question
[140] [Word Break II] [Hard] [Dynamic Programming Backtracking ] 
[Dropbox Google Uber Snapchat Twitter ] 
[139 472].cpp
*/

/* C++ Solution with Backtracking and Memorization for TLE*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        unordered_map<string, vector<string>> m;
        for(int i =0;i<wordDict.size();i++) hash[wordDict[i]] = 1;
        return  recur(s,hash,m);
        

    }
    vector<string> combine( vector<string> prev,string word)
    {
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    vector<string> recur(string s,unordered_map<string,int>& hash,unordered_map<string, vector<string>>& m)
    {
        if(m.count(s)) return m[s]; //take partial solution from cache for TLE
        //if(s.size()<1) return 1;
        vector<string> ans;
        if(hash.count(s)) ans.push_back(s);
        for(int i =0;i<s.size();i++)
        {
            string back = s.substr(i);
            if(hash.count(back))
            {
                //backtracking
                string front = s.substr(0,i);
                //add all possible front segmentation with back
                vector<string> prev = combine(recur(front,hash,m),back);
                //insert all possible input
                ans.insert(ans.end(),prev.begin(),prev.end());
            }
        }
        m[s] = ans;//remember partial  solution for TLE
        return ans;
    }
};


/* my wrong answer */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        for(int i =0;i<wordDict.size();i++) hash[wordDict[i]] = 1;
        vector<string> ans  = {""};
        recur(s,hash,ans,1);
        if(ans[ans.size()-1].empty())ans.pop_back(); 
        return ans;

    }
    int recur(string s,unordered_map<string,int>& hash,vector<string>& ans,int level)
    {
        //cout<<"called recur on s: "<<s<<endl;
        if(hash.count(s)) {ans[ans.size()-1] = s+ans[ans.size()-1]; return 1;}
        if(s.size()<1) return 1;
        for(int i =0;i<s.size();i++)
        {
            if(hash.count(s.substr(0,i)))
            {
                //cout<<"Match first: "<<s.substr(0,i)<<endl;
                if(recur(s.substr(i,s.size()-i),hash,ans,0))
                {
                    //cout<<"here "<<level<<s<<endl;
                    if(level==1)//first call
                    {
                        ans[ans.size()-1] = s.substr(0,i)+" "+ ans[ans.size()-1];
                        ans.push_back(string());
                    }
                    else 
                    {
                        ans[ans.size()-1] = s.substr(0,i)+" "+ ans[ans.size()-1];
                        return 1;
                    }    
                }
            }
        }
        return 0;
    }
};
