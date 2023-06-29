class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int pick = dp[i - 2] + nums[i];
            int not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }
        
        return dp[n-1];
    }
};
