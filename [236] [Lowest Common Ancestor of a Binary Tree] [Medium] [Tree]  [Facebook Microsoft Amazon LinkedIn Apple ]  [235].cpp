/*
Question# + Difficulty + Topic + Company + Similar_Question
[236] [Lowest Common Ancestor of a Binary Tree] [Medium] [Tree] 
[Facebook Microsoft Amazon LinkedIn Apple ] 
[235].cpp
*/

/* Iterative Approach Using DFS */
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
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& route)
    {
        if(!root) return false;
        route.push_back(root);
        if(root==target) return true;
        if(dfs(root->left,target,route)) return true;
        if(dfs(root->right,target,route)) return true;
        route.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> psub,qsub;
        TreeNode* result = nullptr;
        dfs(root,p,psub);
        dfs(root,q,qsub);
        int level = min(psub.size(),qsub.size());
        for(int i=0;i<level;i++)
        {
            if(psub[i]==qsub[i]) result = psub[i];
            else
                break;
        }
        return result;
    }
};

/* Clean Recursive */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
