/*
Question# + Difficulty + Topic + Company + Similar_Question
[111] [ Minimum Depth of Binary Tree] [Easy] [Tree Depth-first Search Breadth-first Search ] 
[] 
[102 104].cpp
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
    int minDepth(TreeNode* root) {
        return recur_depth(root);
    }
    
    int recur_depth(TreeNode* node)
    {
        if(!node) return 0;
        if(!node->left) return 1+ recur_depth(node->right);
        if(!node->right) return 1+ recur_depth(node->left);
        return 1+min(recur_depth(node->right),recur_depth(node->left));
        
    }
};
