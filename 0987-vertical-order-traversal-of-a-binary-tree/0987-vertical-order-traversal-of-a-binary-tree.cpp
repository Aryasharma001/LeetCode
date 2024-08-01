class Solution {
public:
    void func(TreeNode* root, map<int, map<int, multiset<int>>>& nodes, int row, int col) {
        if (root == NULL) return;
        nodes[col][row].insert(root->val);
        func(root->left, nodes, row + 1, col - 1);
        func(root->right, nodes, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // col -> (row -> multiset of values)
        func(root, nodes, 0, 0);
        vector<vector<int>> result;

        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
