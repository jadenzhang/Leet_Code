/*
Question# + Difficulty + Topic + Company + Similar_Question
[60] [Permutation Sequence] [Medium] [Math Backtracking  ] 
[Twitter] 
[31 46].cpp
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> perm(n+1,1);        //factorial pre-calculated
        for(int i = 1; i <=n; i++)  perm[i] = i * perm[i-1];
        
        vector<char> num;         //in-order num set to fetch numbers
        for(int i = 0; i < n; i++) num.push_back('0'+i+1);
        string ans = "";
        while(n > 0) {
            int count = (k-1) / perm[n-1];
            ans += num[count];
            num.erase(num.begin()+count);
            k -= count*perm[n-1];
            n--;
        }
        return ans;
    }
    
};
