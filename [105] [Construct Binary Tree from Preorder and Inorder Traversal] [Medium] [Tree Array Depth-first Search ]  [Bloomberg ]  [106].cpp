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




/* Recursion */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return node;
}

/*
The first element in preorder array can divide inorder array into two parts. Then we can divide preorder array into two parts.
Make this element a node. And the left sub-tree of this node is the left part, right sub-tree of this node is the right part.
This problem can be solved following this logic.
*/
