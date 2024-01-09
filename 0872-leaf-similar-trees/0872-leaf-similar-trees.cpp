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
    void bottomView(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            arr.push_back(root->val);

        bottomView(root->left, arr);
        bottomView(root->right, arr);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        bottomView(root1, arr1);
        bottomView(root2, arr2);

        return arr1 == arr2;
    }
};
