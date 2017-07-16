/*
Question# + Difficulty + Topic + Company + Similar_Question
[107] [Binary Tree Level Order Traversal II] [Easy] [Tree Breadth-first Search  ] 
[] 
[102 637].cpp
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        recur(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void recur(TreeNode* root,vector<vector<int>> &ans,int depth) 
    {
        if(!root) return;
        if(ans.size()<=depth) ans.push_back(vector<int>());
        ans[depth].push_back(root->val);
        if(root->left)  recur(root->left,ans,depth+1);
        if(root->right) recur(root->right,ans,depth+1);       
    }
};
