/*
Question# + Difficulty + Topic + Company + Similar_Question
[94] [Binary Tree Inorder Traversal] [Medium] [Hash Table Stack Tree ] 
[Microsoft ] 
[98 144 145 173 230 272 285 ].cpp
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
    vector<int> inorderTraversal(TreeNode*a root) {
        vector<int> res;
        stack<TreeNode*> stk;
        
        /* we need inorder-> left root right, first go deepest left then its parent and right */
        TreeNode* current = root;
        while(!stk.empty()||current)
        {
            if(current)//go deepest left
            {
                stk.push(current);
                current = current->left;
            }
            else
            {
                TreeNode* tmp = stk.top();
                res.push_back(tmp->val);
                stk.pop();
                current = tmp->right;
            }
        }
    
        return res;
    }
};
