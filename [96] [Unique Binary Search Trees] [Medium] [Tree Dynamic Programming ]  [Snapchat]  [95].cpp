/*
Question# + Difficulty + Topic + Company + Similar_Question
[96] [Unique Binary Search Trees] [Medium] [Tree Dynamic Programming ] 
[Snapchat] 
[95].cpp
*/


/*
Now idea is simple for rest numbers. for n=3 make 1 as root node so there will be 0 nodes in left subtree and 2 nodes in right subtree. we know the solution for 2 nodes that they can be used to make 2 bsts.
Now making 2 as the root node , there will be 1 in left subtree and 1 node in right subtree. ! node results in 1 way for making a BST.
Now making 3 as root node. There will be 2 nodes in left subtree and 0 nodes in right subtree. We know 2 will give 2 BST and zero will give 1 BST.
Totalling the result of all the 3 nodes as root will give 5. Same process can be applied for more numbers.
*/

class Solution {
public:
    int numTrees(int n) {
    int dp[n+1] = {};
    dp[0]= 1;
    dp[1] = 1;
    for(int level = 2; level <=n; level++)
        for(int root = 1; root<=level; root++)
            dp[level] += dp[level-root]*dp[root-1];
    return dp[n];
        
    }
};
