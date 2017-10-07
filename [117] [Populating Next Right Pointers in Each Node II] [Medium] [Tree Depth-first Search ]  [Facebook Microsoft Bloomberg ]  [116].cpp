/*
Question# + Difficulty + Topic + Company + Similar_Question
[117] [Populating Next Right Pointers in Each Node II] [Medium] [Tree Depth-first Search ] 
[Facebook Microsoft Bloomberg ] 
[116].cpp
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
        /* dummy->rootleft-> rootright...
        then take rootleft as root*/
        
        TreeLinkNode* start = new TreeLinkNode(0);
        TreeLinkNode* prev = start;
        while(root)
        {
            if(root->left)
            {
                prev->next = root->left;
                prev = prev->next;
            }
            if(root->right)
            {
                prev->next = root->right;
                prev = prev->next;
            }
            root = root->next;
            if(!root)
            {
                prev = start;
                root = start->next;//go first left
                start->next = NULL;
            }
        }
    }
};
