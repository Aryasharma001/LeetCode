/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root, int level,vector<int>&vis){
        if(root==NULL)
           return;
        if(vis[level]==-1)
           vis[level]=1;
         func(root->left,level+1,vis);
         func(root->right,level+1,vis);  
    }
    int maxDepth(TreeNode* root) {
        vector<int>vis(100000,-1);
        func(root,0,vis);
        int ans=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==1)
                ans=max(ans,i+1);
        }
        return ans;
        
    }
};