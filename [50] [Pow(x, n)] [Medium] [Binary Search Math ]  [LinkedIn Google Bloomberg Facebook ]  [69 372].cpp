/*
Question# + Difficulty + Topic + Company + Similar_Question
[50] [Pow(x, n)] [Medium] [Binary Search Math ] 
[LinkedIn Google Bloomberg Facebook ] 
[69 372].cpp
*/

/* Bit Operation
if LSB of n is 1, then answer * x
Right Shift and Sqare it  x*=x
N = 9 = 2^3 + 2^0 = 1001 in binary. Then:
x^9 = x^(2^3) * x^(2^0)
*/
class Solution {
public:
    double myPow(double x, int n) { 
        if(n==0) return 1;
        if(x==1) return 1;
        if(n<0) {
            x = 1/x;
            if(n==INT_MIN)//INT_MIN = -INT_MAX +1
            {
                x*=x;
                n=INT_MAX;
            }
            else n = -n;

        }
        double ans = 1;
        while(n>0){
            if(n&1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};

/* Another way to handle n = INT_MIN */
class Solution {
public:
    double myPow(double x, int n) { 
        double ans = 1;
        long absN = abs((long)n);
        while(absN > 0) {
            if((absN&1)==1) ans *= x;
            absN >>= 1;
            x *= x;
        }
        return n < 0 ?  1/ans : ans;
    }
};


/* Other recursive ways */
double myPow(double x, int n) {
    if(n<0) return 1/x * myPow(1/x, -(n+1));
    if(n==0) return 1;
    if(n==2) return x*x;
    if(n%2==0) return myPow( myPow(x, n/2), 2);
    else return x*myPow( myPow(x, n/2), 2);
}

double myPow(double x, int n) { 
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}

double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}
