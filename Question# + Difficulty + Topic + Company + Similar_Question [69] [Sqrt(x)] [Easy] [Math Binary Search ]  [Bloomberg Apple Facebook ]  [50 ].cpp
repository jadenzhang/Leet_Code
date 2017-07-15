/*
Question# + Difficulty + Topic + Company + Similar_Question
[69] [Sqrt(x)] [Easy] [Math Binary Search ] 
[Bloomberg Apple Facebook ] 
[50 ].cpp
*/

/* Newton Approach */
class Solution {
public:
    int mySqrt(int x) {
      if (x == 1) return 1;
      long t = x / 2;
      while (t * t > x)
      {
        t = (t + x / t) / 2;
      }
      return t ;
    }
};

/* Binary Search */
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) return 0;
        int left = 1, right = x, ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
