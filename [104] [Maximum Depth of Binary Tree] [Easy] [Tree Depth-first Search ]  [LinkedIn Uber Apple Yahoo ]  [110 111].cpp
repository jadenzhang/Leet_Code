/*
Question# + Difficulty + Topic + Company + Similar_Question
[104] [Maximum Depth of Binary Tree] [Easy] [Tree Depth-first Search ] 
[LinkedIn Uber Apple Yahoo ] 
[110 111].cpp
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
    int maxDepth(TreeNode* root) {
        return recur_depth(root);
    }
    
        
    int recur_depth(TreeNode* node)
    {
        if(!node) return 0;
        if(!node->left) return 1+ recur_depth(node->right);
        if(!node->right) return 1+ recur_depth(node->left);
        return 1+max(recur_depth(node->right),recur_depth(node->left));
        
        
    }
};
