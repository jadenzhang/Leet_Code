/*
Question# + Difficulty + Topic + Company + Similar_Question
[53] [Maximum Subarray] [Easy] [Array Dynamic Programming Divide and Conquer ] 
[LinkedIn Bloomberg Microsoft ] 
[121 152].cpp
*/


/* Iterative Method */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, sum = 0, n = nums.size();
        if(n==1) return nums[0];
        for(int i =0;i<n;i++)
        {
            sum = sum+nums[i];
            max = max<sum? sum:max;
            if(sum<0)sum=0;
        }
        return max;
    }
};

/* Divided and Conquer */
/*Step1. Select the middle element of the array.
So the maximum subarray may contain that middle element or not.

Step 2.1 If the maximum subarray does not contain the middle element, then we can apply the same algorithm to the the subarray to the left of the middle element and the subarray to the right of the middle element.

Step 2.2 If the maximum subarray does contain the middle element, then the result will be simply the maximum suffix subarray of the left subarray plus the maximum prefix subarray of the right subarray

Step 3 return the maximum of those three answer.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n==0) return 0;
        return maxSubArrayHelperFunction(A,0,n-1);
    }
    
    int maxSubArrayHelperFunction(int A[], int left, int right) {
        if(right == left) return A[left];
        int middle = (left+right)/2;
        int leftans = maxSubArrayHelperFunction(A, left, middle);
        int rightans = maxSubArrayHelperFunction(A, middle+1, right);
        int leftmax = A[middle];
        int rightmax = A[middle+1];
        int temp = 0;
        for(int i=middle;i>=left;i--) {
            temp += A[i];
            if(temp > leftmax) leftmax = temp;
        }
        temp = 0;
        for(int i=middle+1;i<=right;i++) {
            temp += A[i];
            if(temp > rightmax) rightmax = temp;
        }
        return max(max(leftans, rightans),leftmax+rightmax);
    }
};
