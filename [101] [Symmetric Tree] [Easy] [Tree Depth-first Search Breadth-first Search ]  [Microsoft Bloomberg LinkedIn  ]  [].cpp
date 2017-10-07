/*
Question# + Difficulty + Topic + Company + Similar_Question
[101] [Symmetric Tree] [Easy] [Tree Depth-first Search Breadth-first Search ] 
[Microsoft Bloomberg LinkedIn  ] 
[].cpp
*/


/* Recursive */
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
    bool recur(TreeNode* left, TreeNode* right)
    {
        if(!left||!right) return left==right;
        if(left->val!=right->val) return false;
        return recur(left->left,right->right)&&recur(left->right,right->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return !root||recur(root->left,root->right);
    }
};

/*Iterative*/
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>lq,rq;
        lq.push(root->left);rq.push(root->right);
        TreeNode* left,*right;
        while(!lq.empty()||!rq.empty())
        {
            left = lq.front();
            lq.pop();
            right = rq.front();
            rq.pop();
            if(!left&&!right) continue;
            if(!left||!right) return false;
            if(left->val!=right->val) return false;
            lq.push(left->left); lq.push(left->right);
            rq.push(right->right);rq.push(right->left);
        }
        return true;
    }
};
