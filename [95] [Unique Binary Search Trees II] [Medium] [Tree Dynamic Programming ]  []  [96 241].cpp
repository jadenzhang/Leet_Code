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
    vector<TreeNode *> generateTree(int from, int to)
    {
        vector<TreeNode *> ret;
        if(to < from) ret.push_back(0);
        if(to  == from) ret.push_back(new TreeNode(from));
        if(to  >  from)
        {
            for(int i=from; i<=to; i++)
            {
                vector<TreeNode *> l = generateTree(from, i-1);
                vector<TreeNode *> r = generateTree(i+1, to);

                for(int j=0; j<l.size(); j++)
                {
                    for(int k=0; k<r.size(); k++)
                    {
                        TreeNode * h = new TreeNode (i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }

    vector<TreeNode *> generateTrees(int n) {
        if(n<1) {
            vector<TreeNode*> nu;
            return nu;
        }  
        return generateTree(1, n);
    }
};
