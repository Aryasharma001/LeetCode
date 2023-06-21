#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    int subproblem = dp[i - coins[j]];
                    if (subproblem != numeric_limits<int>::max()) {
                        dp[i] = min(dp[i], subproblem + 1);
                    }
                }
            }
        }
        
        return (dp[amount] == numeric_limits<int>::max()) ? -1 : dp[amount];
    }
};
