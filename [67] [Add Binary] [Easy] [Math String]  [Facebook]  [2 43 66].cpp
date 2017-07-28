/*
Question# + Difficulty + Topic + Company + Similar_Question
[67] [Add Binary] [Easy] [Math String] 
[Facebook] 
[2 43 66].cpp
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";
        bool carry = 0;
        for(int i =a.size()-1,j = b.size()-1;i>=0||j>=0;i--,j--)
        {
            int sum = 0;
            sum+= i>=0? (int)(a[i]-'0'):0;
            sum+= j>=0? (int)(b[j]-'0'):0;
            if(carry)
            {
                sum++;
                carry = 0;
            }
            if(sum>1)
            {
                carry = 1;
                sum-=2;
            }
            cout<<"Add: "<<sum<<" Str is: "<<str<<endl;
            str = (char)(sum+'0')+str;
        }
        if(carry) str = "1"+str;
        return str;
    }
};
