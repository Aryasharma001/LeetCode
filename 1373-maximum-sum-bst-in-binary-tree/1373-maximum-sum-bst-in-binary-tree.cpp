class Solution {
public:
    // Helper function to check if a subtree is a valid BST and calculate the sum
    tuple<int, int, int, bool> func(TreeNode* root, int& sum) {
        // Base case: If the node is null, it is considered a valid BST with sum 0
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0, true};  // (min value, max value, sum, isBST)
        }

        // Recursively calculate for left and right subtrees
        auto [leftMin, leftMax, leftSum, isLeftBST] = func(root->left, sum);
        auto [rightMin, rightMax, rightSum, isRightBST] = func(root->right, sum);

        // Check if the current tree rooted at 'root' is a BST
        if (isLeftBST && isRightBST && (root->val > leftMax) && (root->val < rightMin)) {
            // If it is a valid BST, calculate the current subtree's sum
            int currSum = leftSum + rightSum + root->val;

            // Update the global maximum sum if the current subtree sum is larger
            sum = max(sum, currSum);

            // Return the updated tuple (current min, current max, current sum, true)
            return {min(root->val, leftMin), max(root->val, rightMax), currSum, true};
        }

        // If it's not a BST, return (min, max, max sum of left or right subtrees, false)
        return {INT_MIN, INT_MAX, max(leftSum, rightSum), false};
    }

    // Main function to find the maximum sum of any BST subtree
    int maxSumBST(TreeNode* root) {
        int sum = 0;  // To store the maximum sum
        auto [minVal, maxVal, maxSum, isBST] = func(root, sum);
        return sum;  // Return the global maximum sum
    }
};
