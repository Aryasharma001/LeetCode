class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false; // If the last element is '1', we can't reach the end.

        vector<int> dp(n, 0);
        dp[0] = 1;

        int prefixSum = 0;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump) {
                prefixSum += dp[i - minJump];
            }
            if (i > maxJump) {
                prefixSum -= dp[i - maxJump - 1];
            }

            if (s[i] == '0' && prefixSum > 0) {
                dp[i] = 1;
            }
        }

        return dp[n - 1] == 1;
    }
};
