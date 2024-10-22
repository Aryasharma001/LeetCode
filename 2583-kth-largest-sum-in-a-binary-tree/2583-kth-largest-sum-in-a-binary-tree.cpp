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
    void bfs(TreeNode* root,vector<vector<int>>&traversal, int level ){
        if(root==NULL)
            return;
        if (traversal.size() == level)
            traversal.push_back(vector<int>());
        traversal[level].push_back(root->val);
        bfs(root->left,traversal,level+1);
        bfs(root->right,traversal,level+1);
        
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        vector<vector<int>>traversal;
        bfs(root,traversal,0);
        if(traversal.size()<k)
            return -1;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int i = 0; i < traversal.size(); i++) {
            long long levelSum = 0;
            for (int val : traversal[i]) {
                levelSum += val;
            }

            // Insert levelSum into the min-heap
            if (minHeap.size() < k) {
                minHeap.push(levelSum); // Add if heap size is less than k
            } else if (levelSum > minHeap.top()) {
                minHeap.pop(); // Remove smallest element if new sum is larger
                minHeap.push(levelSum); // Add the new sum
            }
        }
        return minHeap.top();
    }
};