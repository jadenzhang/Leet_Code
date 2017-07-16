/*
Question# + Difficulty + Topic + Company + Similar_Question
[227] [Basic Calculator II] [Medium] [String] 
[Airbnb] 
[224 282].cpp
*/

/*
I used a variable 'interim' to calculate interim result. interim result are separated by either '-' or '+'. For example, "1 +2 * 4-5/3", there will be three interims: (+)1, (+)2 * 4, (-)5/3.

Here is the process, each time, we read a character:

If it's a digit, we continue reading until a non-digit appears, we record the number as "num". Then we check the operator before this num as to update the current interim result. Note that, there is no operator before the first number in expressions, so op is initialized to be '+'. Also note that, when a '+' or '-' appears, it means the end of current interim calculation, which should be added to the final answer, and then we reset interim for the next 'interim calculation'.

If it's ' ', we skip;
*/
class Solution {
public:
    int calculate(string s) {
        int i = 0, ans = 0, num = 0;
        int interim = 0;
        char op = '+';
        while(i < s.size()){
            if(isdigit(s[i])){
                num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                if(op == '+' || op == '-'){
                    ans += interim;
                    interim = num * (op == '-' ? -1 : 1);
                }else if(op == '*'){
                    interim *= num;
                }else if(op == '/'){
                    interim /= num;
                }
                continue;
            }
            else if(s[i] != ' ') op = s[i];
           
            i++;
        }    

        ans += interim;            
        return ans;
    }
};
