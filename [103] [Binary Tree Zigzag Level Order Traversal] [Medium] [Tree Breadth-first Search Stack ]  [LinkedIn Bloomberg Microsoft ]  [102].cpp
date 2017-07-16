Question# + Difficulty + Topic + Company + Similar_Question
[103] [Binary Tree Zigzag Level Order Traversal] [Medium] [Tree Breadth-first Search Stack ] 
[LinkedIn Bloomberg Microsoft ] 
[102].cpp
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recur(root,ans,0);
        return ans;
    }
    
    void recur(TreeNode* root,vector<vector<int>> &ans,int depth) 
    {
        if(!root) return;
        if(ans.size()<=depth) ans.push_back(vector<int>());
        if(!(depth%2))ans[depth].push_back(root->val);
        else ans[depth].insert(ans[depth].begin(),root->val);
        if(root->left)  recur(root->left,ans,depth+1);
        if(root->right) recur(root->right,ans,depth+1);       
    }
};



/* Iterative Approach */
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool zigzag = 1;
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                zigzag  = !zigzag;
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                if(zigzag)cur_vec.push_back(t->val);
                else cur_vec.insert(cur_vec.begin(),t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};
