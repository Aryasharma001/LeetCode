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
    void func(TreeNode* node, vector<vector<int>>& nums, vector<int>& temp) {
        if (node == NULL) {
            return;
        } 

        temp.push_back(node->val);  // Include the current node's value in the path

        // Check if the current node is a leaf node
        if (node->left == NULL && node->right == NULL) {
            nums.push_back(temp);  // If it's a leaf node, add the path to the result
        } else {
            // Recursively traverse the left and right subtrees
            func(node->left, nums, temp);
            func(node->right, nums, temp);
        }

        temp.pop_back();  // Remove the current node's value after traversing its subtree
}

    
    int sumNumbers(TreeNode* root) {
        vector<vector<int>>nums;
        int ans=0;
        vector<int>temp;
        func(root,nums,temp);
        for(auto it:nums){
            for(int j=0;j<it.size();j++){
                //cout<<it[j]<<" ";
                ans+=it[j]*pow(10,(it.size()-j-1));
             }
            //cout<<endl;
        }
        return ans;
    }
    
};