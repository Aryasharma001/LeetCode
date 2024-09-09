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
    TreeNode* func(vector<int>& preorder,int& i, int bound){
        if(i>=preorder.size()||preorder[i]>bound){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=func(preorder,i,node->val);
        node->right=func(preorder,i,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=0;
        return func(preorder,mini,INT_MAX);
    }
};