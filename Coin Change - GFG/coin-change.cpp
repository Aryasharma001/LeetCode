//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  long long int f(int coins[],int N,int sum,int i,vector<vector<long long int>>&dp){
      
    
    if(sum==0){
        return 1;
    }
    if(i<0 || sum<0)
    return 0;
    
    if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
    // pick the coin 
    long long int pick=0;
    if(coins[i]<=sum)
    pick=f(coins,N,sum-coins[i],i,dp);
    
     return dp[i][sum]=pick+f(coins,N,sum,i-1,dp);
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        long long int count=0;
        //sort(coins,coins+N);
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        return f(coins,N,sum,N-1,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends