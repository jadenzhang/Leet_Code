/*
Question# + Difficulty + Topic + Company + Similar_Question
[106] [Construct Binary Tree from Inorder and Postorder Traversal] [Medium] [Tree Array Depth-first Search ] 
[Microsoft] 
[105].cpp
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inpos = inorder.size()-1;
        int postpos = postorder.size()-1;
        if(inpos<0 || postpos<0) return NULL;
        stack<TreeNode*> waiting;
        TreeNode* prev = NULL;
        TreeNode* root = new TreeNode(postorder[postpos]);
        waiting.push(root);
        postpos--;
        
        while(postpos>=0)
        {
            if(!waiting.empty() && waiting.top()->val == inorder[inpos])
            {
                prev = waiting.top();
                waiting.pop();
                inpos--;
            }
            else
            {
                TreeNode* tmp = new TreeNode(postorder[postpos]);
                if(prev)//add to left
                {
                    prev->left = tmp;   
                }
                else if(!waiting.empty())//add to right
                {
                    TreeNode* curtop = waiting.top();
                    curtop->right = tmp;
                }
                waiting.push(tmp);
                prev = NULL;
                postpos--;
            }
        }
        return root;
    }
};
/*
This is my iterative solution, think about "Constructing Binary Tree from inorder and preorder array", 
the idea is quite similar. Instead of scanning the preorder array from beginning to end and using inorder array as a kind of mark, 
in this question, the key point is to scanning the postorder array from end to beginning and also 
use inorder array from end to beginning as a mark because the logic is more clear in this way. The core idea is: 
Starting from the last element of the postorder and inorder array, we put elements from postorder array to a stack and 
each one is the right child of the last one until an element in postorder array is equal to the element on the inorder array.
Then, we pop as many as elements we can from the stack and decrease the mark in inorder array until the peek() element is 
not equal to the mark value or the stack is empty. Then, the new element that we are gonna scan from postorder array is
the left child of the last element we have popped out from the stack.
*/



/*Recursive */

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

TreeNode* create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(postorder[pe]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
    node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
    return node;
}


