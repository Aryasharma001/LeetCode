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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(rh,lh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(height(root->left)-height(root->right))>1)
            return false;
        bool isLeftBalanced=isBalanced(root->left);
        bool isRightBalanced=isBalanced(root->right);
        return isLeftBalanced && isRightBalanced;
    }
};