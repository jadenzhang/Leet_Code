/*
Question# + Difficulty + Topic + Company + Similar_Question
[88] [Merge Sorted Array] [Easy] [Array Two Pointers ] 
[Facebook Microsoft Bloomberg ] 
[21].cpp
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m1 = m-1,n1 = n-1,tar = m+n-1;
        for(int i=m+n-1;i>=0;i--)
        {
            nums1[i] = (m1<0)? nums2[n1--]:(n1<0)? nums1[m1--]:(nums1[m1]<nums2[n1])?nums2[n1--]:nums1[m1--]; 
        }       
    }
};
