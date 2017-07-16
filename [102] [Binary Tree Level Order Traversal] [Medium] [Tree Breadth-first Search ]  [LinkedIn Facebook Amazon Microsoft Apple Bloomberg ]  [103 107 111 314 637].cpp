/*
Question# + Difficulty + Topic + Company + Similar_Question
[102] [Binary Tree Level Order Traversal] [Medium] [Tree Breadth-first Search ] 
[LinkedIn Facebook Amazon Microsoft Apple Bloomberg ] 
[103 107 111 314 637].cpp
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recur(root,ans,0);
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


/* Non Recursive, Use Queue and NULL to sentinal end of each level*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};
