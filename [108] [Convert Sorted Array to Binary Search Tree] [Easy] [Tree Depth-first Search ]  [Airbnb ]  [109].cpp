/*
Question# + Difficulty + Topic + Company + Similar_Question
[108] [Convert Sorted Array to Binary Search Tree] [Easy] [Tree Depth-first Search ] 
[Airbnb ] 
[109].cpp
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(vector<int>& nums,int cur, int end)
    {
        if(cur>=end) return NULL;
        int mid = (end+cur)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = recur(nums,cur,mid);
        root->right = recur(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return recur(nums,0,nums.size());;
        
    }
};
