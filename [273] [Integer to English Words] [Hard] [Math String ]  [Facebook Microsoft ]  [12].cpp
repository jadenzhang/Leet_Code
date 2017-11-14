/*
Question# + Difficulty + Topic + Company + Similar_Question
[273] [Integer to English Words] [Hard] [Math String ] 
[Facebook Microsoft ] 
[12].cpp
*/


class Solution {
public:

    string numberToWords(int n) {
        if(!n) return "Zero";
        return recur(n).substr(1);
    }
    string recur(int n)
    {
        if(n>= 1000000000) return recur(n/1000000000)+" Billion"+recur(n-1000000000*(n/1000000000));
        else if(n>= 1000000) return recur(n/1000000)+" Million"+ recur(n-1000000*(n/1000000));
        else if(n>= 1000) return recur(n/1000)+" Thousand"+recur(n-1000*(n/1000));
        else if(n>= 100) return recur(n/100)+" Hundred"+recur(n-100*(n/100));
        else if(n>=20) return " "+over_twenty[n/10 -2]+recur(n-10*(n/10));
        else if(n>=1) return " "+below_twenty[n-1];
        else return"";
    }
    string below_twenty[19] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string over_twenty[8] ={"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
