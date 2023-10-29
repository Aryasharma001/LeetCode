int mod = 1e9+7;
class Solution {
public:
    long long dp[30000][6];
    long long f(int n,int i,vector<int>adj[]){
        if(n==0) return 1;
        long long ans = 0;
        if(dp[n][i]!= -1) return dp[n][i];
        for(auto it : adj[i-1]){
            ans+=f(n-1,it,adj);
            ans%=mod;
        }
        return dp[n][i] = ans%mod;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>adj[5] = {{2},{1,3},{1,2,4,5},{3,5},{1}};
        long long cnt = 0;
        for(int i = 1;i<6;i++){
           cnt+=f(n-1,i,adj);
           cnt%=mod;
        }
        return (int)cnt;
    }
};