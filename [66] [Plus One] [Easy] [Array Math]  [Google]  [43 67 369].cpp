/*
Question# + Difficulty + Topic + Company + Similar_Question
[66] [Plus One] [Easy] [Array Math] 
[Google] 
[43 67 369].cpp
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i =n-1;i>=0;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
                if(i==0) digits.insert(digits.begin(),1);
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        return digits;
    }
};
