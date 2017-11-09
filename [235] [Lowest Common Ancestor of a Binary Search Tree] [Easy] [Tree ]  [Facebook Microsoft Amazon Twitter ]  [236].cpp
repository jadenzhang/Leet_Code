/*
Question# + Difficulty + Topic + Company + Similar_Question
[235] [Lowest Common Ancestor of a Binary Search Tree] [Easy] [Tree ] 
[Facebook Microsoft Amazon Twitter ] 
[236].cpp
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* prev = root;
        TreeNode* cur = root;
        while(cur)
        {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};
