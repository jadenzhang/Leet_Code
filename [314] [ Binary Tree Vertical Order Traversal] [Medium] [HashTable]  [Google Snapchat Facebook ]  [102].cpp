/*
Question# + Difficulty + Topic + Company + Similar_Question
[314] [ Binary Tree Vertical Order Traversal] [Medium] [HashTable] 
[Google Snapchat Facebook ] 
[102].cpp
*/


/* My version with recursion, However, recursion will not reserve the order because left always add first than right
so it might end up with bottom element appear before top element
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<vector<int>> left{{0}};
        vector<vector<int>> right;
        recur(root,left,right,0);
        for(int i =left.size()-1;i>0;i--) ans.push_back(left[i]);
        for(int i =0;i<right.size();i++) ans.push_back(right[i]);
        return ans;
    }
    
    void recur(TreeNode* root,vector<vector<int>> &left,vector<vector<int>> &right,int pos) 
    {
        if(!root) return;
        if(right.size()==pos) right.push_back(vector<int>());
        else if(left.size()==(-pos)) left.push_back(vector<int>());
        if(pos>=0) {right[pos].push_back(root->val);cout<<"Add "<<root->val<<"to "<<pos<<endl;}
        else if(pos<0) {left[-pos].push_back(root->val);cout<<"Add "<<root->val<<"to "<<pos<<endl;}
        
      
        if(root->left)  recur(root->left,left,right,pos-1);
        if(root->right) recur(root->right,left,right,pos+1); 
    }
};




/* A better Iterative approach using Hashtable and Queue
Queue will ensure the top element will appear earlier than bottom element
*/
vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<int>> cols;
    queue<pair<TreeNode*, int>> q;
    if (root)
        q.emplace(root, 0);
    while (q.size()) {
        auto node = q.front().first;
        int x = q.front().second;
        q.pop();
        cols[x].push_back(node->val);
        if (node->left)
            q.emplace(node->left, x-1);
        if (node->right)
            q.emplace(node->right, x+1);
    }
    vector<vector<int>> result;
    for (auto col : cols)
        result.push_back(col.second);
    return result;
}
