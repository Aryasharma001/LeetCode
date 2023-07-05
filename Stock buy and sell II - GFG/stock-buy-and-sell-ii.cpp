//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

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
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp);
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends