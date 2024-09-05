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
    void preOrderFunc(TreeNode* root, vector<TreeNode*>&preOrder){
        if(root==NULL)
            return;
        
        preOrder.push_back(root);
        preOrderFunc(root->left,preOrder);
        preOrderFunc(root->right,preOrder);
        
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>preOrder;
        TreeNode* rootTemp=root;
        preOrderFunc(rootTemp,preOrder);
        int i=0;
        if(preOrder.size()!=1){
            
            while(i<preOrder.size()){
            root->left=NULL;
            root->right=preOrder[i];
            root=root->right;
            i++;
        }
        }
    }
};