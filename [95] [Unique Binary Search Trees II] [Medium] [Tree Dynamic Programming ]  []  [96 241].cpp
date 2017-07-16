/*
Question# + Difficulty + Topic + Company + Similar_Question
[95] [Unique Binary Search Trees II] [Medium] [Tree Dynamic Programming ] 
[] 
[96 241].cpp
*/

/*
explaination:
Given a tree which n nodes, it has the follwing form:
(0)root(n-1)
(1)root(n-2)
(2)root(n-3)
where (x) denotes the trees with x nodes.

Now take n=3 for example. Given n=3, we have [1 2 3] in which each of them can be used as the tree root.

when root=1: [1 # 2 # 3]; [1 # 3 2];
when root=2: [2 1 3];
when root=3: (similar with the situations when root=1.)

Thus, if we write a recursive function who generates a group of trees in which the numbers range from f to t, we have to generate the left trees and right trees of each tree in the vector.
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
    int minDepth(TreeNode* root) {
        return recur_depth(root);
    }
    
    int recur_depth(TreeNode* node)
    {
        if(!node) return 0;
        if(!node->left) return 1+ recur_depth(node->right);
        if(!node->right) return 1+ recur_depth(node->left);
        return 1+min(recur_depth(node->right),recur_depth(node->left));
        
    }
};
