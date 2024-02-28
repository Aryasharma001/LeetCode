class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) // Handle the case when the input vector is empty
            return 0;
        
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] represents the length of LIS ending at index i
        int maxLength = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1); // Update the length of LIS ending at index i
                    maxLength = max(maxLength, dp[i]); // Update the overall maximum length
                }
            }
        }

        return maxLength;
    }
};
