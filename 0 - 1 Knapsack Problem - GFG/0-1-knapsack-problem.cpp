//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int W,int wt[],int val[],int n,int i,vector<vector<int>>&dp){
        if(W<=0 || i==n){
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        
        int take=0,not_take=0;
        //take the item
        
        if(W>=wt[i]){
            take=val[i]+f((W-wt[i]),wt,val,n,i+1,dp);
        }
        not_take=f(W,wt,val,n,i+1,dp);
        return dp[i][W]=max(take,not_take);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return f(W,wt,val,n,0,dp);
       
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends