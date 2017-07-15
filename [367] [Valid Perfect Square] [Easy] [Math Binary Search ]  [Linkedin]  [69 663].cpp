/*
Question# + Difficulty + Topic + Company + Similar_Question
[367] [Valid Perfect Square] [Easy] [Math Binary Search ] 
[Linkedin] 
[69 663].cpp
*/


/* Use the fact that all perfect square number are sum of consecutive Odd numbers: 1+3+5+7...*/
class Solution {
public:
    bool isPerfectSquare(int n) {
        int i = 1;
        for (; ; )
        {
            if (n < 0)
                return false;
            if (n == 0)
                return true;
            n -= i;
            i += 2;
        }
    }
};



/*binary search. Time Complexity O(logN)*/
    public boolean isPerfectSquare(int num) {
      if (num < 1) return false;
      long left = 1, right = num;// long type to avoid 2147483647 case
    
      while (left <= right) {
        long mid = left + (right - left) / 2;
        long t = mid * mid;
        if (t > num) {
          right = mid - 1;
        } else if (t < num) {
          left = mid + 1;
        } else {
          return true;
        }
      }
    
      return false;
    }
    
    
    
    
/*Newton Method. See [this wiki page][1]. Time Complexity is close to constant, given a positive integer.*/

    boolean isPerfectSquare(int num) {
      if (num < 1) return false;
      long t = num / 2;
      while (t * t > num) {
        t = (t + num / t) / 2;
      }
      return t * t == num;
    }
