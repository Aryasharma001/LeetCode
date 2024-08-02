#include <vector>


class Solution {
public:
    void func(TreeNode* root, int row, vector<deque<unsigned long long>>& levels, unsigned long long index) {
        if (root == nullptr) return;
        if (levels.size() == row) {
            levels.push_back({});
        }
        levels[row].push_back(index);
        func(root->left, row + 1, levels, 2 * index + 1);
        func(root->right, row + 1, levels, 2 * index + 2);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<deque<unsigned long long>> levels;
        func(root, 0, levels, 0);
        unsigned long long ans = 0;
        for (const auto& it : levels) {
            if (!it.empty()) {
                ans = max(ans, it.back() - it.front() + 1);
            }
        }
        return static_cast<int>(ans);
    }
};
