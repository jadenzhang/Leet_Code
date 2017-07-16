/*
Question# + Difficulty + Topic + Company + Similar_Question
[637] [Average of Levels in Binary Tree] [Easy] [Tree] 
[Facebook] 
[102 107].cpp
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> count;
        recur(root,ans,count,0);
        for(int i =0;i<ans.size();i++) ans[i] /= count[i];
        return ans;
    }
    void recur(TreeNode* root, vector<double> &ans,vector<int> &count, int depth)
    {
        if(!root)return;
        if(ans.size()<=depth) {ans.push_back(double(0));count.push_back(int(0));}
        ans[depth]+=root->val;
        count[depth]++;
        if(root->left) recur(root->left,ans,count,depth+1);
        if(root->right) recur(root->right,ans,count,depth+1);
    }
};
