/*
Question# + Difficulty + Topic + Company + Similar_Question
[105] [Construct Binary Tree from Preorder and Inorder Traversal] [Medium] [Tree Array Depth-first Search ] 
[Bloomberg ] 
[106].cpp
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(!n) return 0;
        
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* tmp = root;
        stack<int> sta;
        sta.push(preorder[0]);
        stack<TreeNode*> waiting;
        waiting.push(root);
        
        int prenum = 1,innum=0,flag = 0;//flag==1 means adding to right otherwise left
        while(prenum<n)
        {
            if(!waiting.empty() && (waiting.top())->val == inorder[innum])//start for next right
            {
                tmp = waiting.top();
                waiting.pop();
                sta.pop();
                flag = 1;
                innum++;//iterating inorder to the cur pos
                cout<<"here";
            }
            else// traversing
            {
                if(flag)//right
                {
                    flag = 0;
                    sta.push(preorder[prenum]);
                    tmp->right = new TreeNode(preorder[prenum]);
                    tmp = tmp->right;
                    waiting.push(tmp);
                    prenum++;
                }
                else//left
                {
                    sta.push(preorder[prenum]);
                    tmp->left = new TreeNode(preorder[prenum]);
                    tmp = tmp->left;
                    waiting.push(tmp);
                    prenum++;
                    cout<<"left";
                }
            }
        }
        return root;
    }
};
