class Solution {
  public:
    long f(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
            
        }
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        
        if(buy==0){
            int take=-prices[i]+f(i+1,1,prices,dp);
            int not_take=0+f(i+1,0,prices,dp);
            return dp[i][buy]=max(take,not_take);
        }
        else{
            int take=prices[i]+f(i+1,0,prices,dp);
            int not_take=0+f(i+1,1,prices,dp);
            return dp[i][buy]=max(take,not_take);
        }
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp);
        
        
    }
};
