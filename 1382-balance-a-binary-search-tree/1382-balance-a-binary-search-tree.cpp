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

// if we do a binary partition on a asc irdeer elements it creates a BST
// for ascending order we can do Inorder traversal

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int>inorder;
        inorderTraversal(root,inorder);
        return constructBST(inorder,0,(inorder.size()-1));
        
        
    }
    TreeNode* constructBST(vector<int>in,int low,int high){
        if(low>high) return NULL;
        int mid=low+(high-low)/2;
        TreeNode* curr= new TreeNode(in[mid]);
        curr->left=constructBST(in,low,mid-1);
        curr->right=constructBST(in,mid+1,high);
        return curr;
        
    }
    void inorderTraversal(TreeNode* root,vector<int>&inorder){
        if(!root) return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
};