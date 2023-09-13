class Solution {
public:
    void generateSubsets(int start, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset); // Add the current subset to the result
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates to avoid duplicate subsets
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            subset.push_back(nums[i]); // Include the current element in the subset
            generateSubsets(i + 1, nums, subset, result); // Recursively generate subsets
            subset.pop_back(); // Backtrack and remove the current element from the subset
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        
        generateSubsets(0, nums, subset, result);
        
        return result;
    }
};
