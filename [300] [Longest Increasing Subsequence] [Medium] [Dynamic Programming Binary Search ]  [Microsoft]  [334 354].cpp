/*
Question# + Difficulty + Topic + Company + Similar_Question
[300] [Longest Increasing Subsequence] [Medium] [Dynamic Programming Binary Search ] 
[Microsoft] 
[334 354].cpp
*/


/* Easy O(N^2) Solution */
/*Basically check all possible subsequence*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int max = INT_MIN;
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;//initilization for case if i is the smallest
            for(int sub = 0;sub<i;sub++)//backtracking
            {
                if(nums[i]>nums[sub]) dp[i] = dp[i]> dp[sub]+1? dp[i]:dp[sub]+1;
            }
            //update max after one iteration
            max = dp[i]>max? dp[i]:max;
        }
        return max;
    }
};

/* Better O(N log N) Solution */
/*
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
 
    return length;
}
 
int main() {
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    std::cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequenceLength(v) << 'n';
   return 0;
}
*/
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
