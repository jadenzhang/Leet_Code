/*
Question# + Difficulty + Topic + Company + Similar_Question
[32] [ Longest Valid Parentheses] [Hard] [Dynamic Programming String  ] 
[] 
[20].cpp
*/



/* STACK APPROACH 
Time complexity : O(n). nn is the length of the given string.

Space complexity : O(n). The size of stack can go up to n.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> par;
        int max = 0,cur = 0;   
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                par.push(i);
            }
            else if(s[i]==')')
            {
                if(!par.empty() && s[par.top()]=='(')//Match
                {
                    par.pop();
                    int last = -1;//To Add two for ()
                    if(!par.empty()) {last = par.top();}//Extend length to last invalid parenthesis
                    cur = i-last;
                    max = max>cur? max:cur;
                }
                else// not match
                {
                    par.push(i);
                }
            }
        }
        return max;
    }
};


/* Two Pointers APPROACH 
Complexity Analysis

Time complexity : O(n). Two traversals of the string.

Space complexity : O(1) Only two extra variables leftleft and rightright are needed.

In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string from the left towards the right and for every 
‘(’
‘(’ encountered, we increment the leftleft counter and for every 
‘)’
‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.

Next, we start traversing the string from right to left and similar procedure is applied.
*/

/* JAVA*/
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
