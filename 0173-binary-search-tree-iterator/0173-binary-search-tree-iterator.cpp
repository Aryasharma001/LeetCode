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
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    // Traverse the leftmost part of the tree
    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // Return the next smallest number
    int next() {
        TreeNode* node = st.top();
        st.pop();
        // If the node has a right child, process its right subtree
        if (node->right != nullptr) {
            pushLeft(node->right);
        }
        return node->val;
    }
    
    // Return whether we have a next smallest number
    bool hasNext() {
        return !st.empty();  // should return true if there are still nodes left
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
