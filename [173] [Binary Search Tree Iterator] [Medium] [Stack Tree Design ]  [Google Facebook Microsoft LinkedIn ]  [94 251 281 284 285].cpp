/*
Question# + Difficulty + Topic + Company + Similar_Question
[173] [Binary Search Tree Iterator] [Medium] [Stack Tree Design ] 
[Google Facebook Microsoft LinkedIn ] 
[94 251 281 284 285].cpp
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> sta;
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            sta.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = sta.top();
        int val = cur->val;
        sta.pop();
        cur = cur->right;
        while(cur)
        {
            sta.push(cur);
            cur = cur->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
