/*
Question# + Difficulty + Topic + Company + Similar_Question
[12] [Integer to Roman] [Medium] [Math String ] 
[Twitter ] 
[13 273].cpp
*/



class Solution {
public:
    string intToRoman(int num) {
        map <int,string, greater<int>> hash = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                {400, "CD"}, {100, "C"}, {90, "XC"}, 
                                {50, "L"}, {40, "XL"}, {10, "X"}, 
                                {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string str;
        while(num)
        {
            for(const auto& itr:hash)
            {
                if(itr.first<=num)
                {
                    num-=itr.first;
                    str+=itr.second;
                    break;
                }
            }
        }
        return str;
    }
};

public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

