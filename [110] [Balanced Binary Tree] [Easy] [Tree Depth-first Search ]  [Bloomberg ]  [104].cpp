/*
Question# + Difficulty + Topic + Company + Similar_Question
[110] [Balanced Binary Tree] [Easy] [Tree Depth-first Search ] 
[Bloomberg ] 
[104].cpp
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
int recur (TreeNode *root) {
        if (root == NULL) return 0;
        
        int left = recur (root -> left);
        int right = recur (root -> right);
        if (right == -1|| left==-1||abs(left - right) > 1) return -1;
        return max (left, right) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return recur (root) != -1;
    }
};
