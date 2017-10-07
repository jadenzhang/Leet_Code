/*
Question# + Difficulty + Topic + Company + Similar_Question
[98] [Validate Binary Search Tree] [Medium] [Tree Depth-first Search  ] 
[Facebook Microsoft Amazon Bloomberg ] 
[94 501].cpp
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
    bool check(TreeNode* root, TreeNode* Min,TreeNode* Max)
    {
        if(!root) return true;
        if((Min && root->val <=Min->val) ||(Max && root->val >=Max->val))
            return false;
        return check(root->left,Min,root)&& check(root->right,root,Max);
        
    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
};
