class Solution {
public:
    void generate_subsequences(string s , int i,set<string>&subs,string &ans){
        if(i==s.size()){
            subs.insert(ans);
            ans="";
            return;
        }
        string temp=ans+s[i];
        generate_subsequences(s,i+1,subs,temp);
        generate_subsequences(s,i+1,subs,ans);
    }
    int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D DP table to store the length of the longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill in the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
};