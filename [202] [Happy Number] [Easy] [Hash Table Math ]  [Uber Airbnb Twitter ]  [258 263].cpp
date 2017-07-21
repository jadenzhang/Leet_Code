/*
Question# + Difficulty + Topic + Company + Similar_Question
[202] [Happy Number] [Easy] [Hash Table Math ] 
[Uber Airbnb Twitter ] 
[258 263].cpp
*/

/* Florida Cycle Detection to break loop */
class Solution {
public:
    bool isHappy(int n) 
    {
        int slow = n,fast = n;
        do
        {
            slow = getsum(slow);
            fast = getsum(fast);
            fast = getsum(fast);
        }while(fast!=slow);
        return fast==1;
    }
    
    int getsum(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            sum+=pow((n%10),2);
            n/=10;
        }
        return sum;
    }
};

/* Hash approach */
class Solution {
public:
    bool isHappy(int n) 
    {
        unordered_map<int,int> hash;
        while(!hash.count(n))
        {
            hash[n] = 1;
            n = getsum(n);
        }
        return n==1;
        
    }
    
    int getsum(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            sum+=pow((n%10),2);
            n/=10;
        }
        return sum;
    }
};
