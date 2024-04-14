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
    void left_leaf(int &sum,TreeNode* node){
        if(node==NULL){
            return;
        }
        if( node->left!=NULL && node->left->left==NULL && node->left->right == NULL){
            sum+=node->left->val;
        }
        left_leaf(sum,node->left);
        left_leaf(sum,node->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        left_leaf(sum,root);
        return sum;
    }
};