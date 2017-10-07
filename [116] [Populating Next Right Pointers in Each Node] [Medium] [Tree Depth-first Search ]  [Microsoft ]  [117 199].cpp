/*
Question# + Difficulty + Topic + Company + Similar_Question
[116] [Populating Next Right Pointers in Each Node] [Medium] [Tree Depth-first Search ] 
[Microsoft ] 
[117 199].cpp
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* parent = root;
        while(parent)
        {
            TreeLinkNode* cur = parent;
            while(cur)
            {
                if(cur->left) cur->left->next = cur->right;//same parent
                if(cur->right&& cur->next) cur->right->next = cur->next->left;// across parent
                cur = cur->next;//go right
            }
            parent = parent->left;//go down
        }
    }
};
