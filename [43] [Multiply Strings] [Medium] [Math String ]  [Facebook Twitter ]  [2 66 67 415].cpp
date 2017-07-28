/*
Question# + Difficulty + Topic + Company + Similar_Question
[43] [Multiply Strings] [Medium] [Math String ] 
[Facebook Twitter ] 
[2 66 67 415].cpp
*/

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size(), n = num2.size();
        int ary [m+n] = {0};
        for(int i =m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                int val = (num1[i]-'0')*(num2[j]-'0');
                int sum = val+ary[i+j+1];
                
                ary[i+j] +=sum/10;
                ary[i+j+1] = sum%10;
               // cout<<"overflow : "<<ary[i+j]<<"val : "<<ary[i+j+1]<<endl;
                
            }
        }
        
        string str = "";
        int i =0;
        while(i<m+n&&ary[i]==0) i++;
        while(i<m+n) 
        {
           // cout<<(char)(ary[i]+'0')<<" ";
            str+=((char)(ary[i]+'0')); 
            i++;
        }
        return str.empty()? "0":str;
    }
};
/*
                             1    2   3
                                  4   5
------------------------------------------
                                  1   5
                             1    0
                        0    5
                        
                             1    2
                        0    8
                    0   4
------------------------------------------
Index [0,1,2,3,4]

Indices[i+j , i+j+1]
<------------
                   
*/

