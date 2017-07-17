/*
Question# + Difficulty + Topic + Company + Similar_Question
[563] [Binary Tree Tilt] [Easy] [Tree] 
[Indeed] 
[].cpp
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
    int findTilt(TreeNode* root) {
        int ans = 0;
        recur(root,ans);
        return ans;
    }
    
    int recur(TreeNode*root, int& ans)
    {
        if(!root) return 0;
        int a = recur(root->left,ans);
        int b = recur(root->right,ans);
        ans+= abs(a-b);
        return a+b+root->val;
    }

};
