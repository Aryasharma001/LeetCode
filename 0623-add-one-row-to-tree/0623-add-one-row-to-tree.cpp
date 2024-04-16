class Solution {
public:
    void leftTree(TreeNode* node, int val, int depth) {
        if (depth == 2) {
            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            TreeNode* nextNodeLeft = node->left;
            TreeNode* nextNodeRight = node->right;
            node->left = newLeftNode;
            node->right = newRightNode;
            newLeftNode->left = nextNodeLeft;
            newRightNode->right = nextNodeRight;
            return;
        }
        if (node->left) leftTree(node->left, val, depth - 1);
        if (node->right) leftTree(node->right, val, depth - 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        leftTree(root, val, depth);
        return root;
    }
};
