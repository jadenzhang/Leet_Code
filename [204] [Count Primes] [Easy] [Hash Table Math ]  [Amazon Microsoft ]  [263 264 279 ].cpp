/*
Question# + Difficulty + Topic + Company + Similar_Question
[204] [Count Primes] [Easy] [Hash Table Math ] 
[Amazon Microsoft ] 
[263 264 279 ].cpp
*/


class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        bool hash[n] = {false};
        int count = 0;
        int upper = sqrt(n);//ignore duplicated mutiplication
        for(int i =2;i<n;i++)
        {
            if(!hash[i])
            {
                count++;
                if(i>upper) continue;
                for(int j = 2;i*j<n;j++)
                    hash[i*j]=true;
            }
        }
        return count;
    }
};
