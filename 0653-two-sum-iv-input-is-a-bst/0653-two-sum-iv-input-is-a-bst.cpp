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
     void inorder(vector<int>&in,TreeNode* node){
        if(node==NULL) return;
        inorder(in,node->left);
        in.push_back(node->val);
        inorder(in,node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>in;
        inorder(in,root);
        int st=0,end=in.size()-1;
        while(st<end){
            if(in[st]+in[end]==k)
                return true;
            if(in[st]+in[end]<k)
                st++;
            else
                end--;
        }
        return false;
    }
};