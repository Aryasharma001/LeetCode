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
    int func(TreeNode* root,int& diameter){
        if(!root) return 0;
        int rh=func(root->left,diameter);
        int lh=func(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return max(rh,lh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        func(root,diameter);
        return diameter;
    }
};