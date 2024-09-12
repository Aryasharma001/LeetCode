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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>in;
        inorder(in,root);
        return in[k-1];
    }
};