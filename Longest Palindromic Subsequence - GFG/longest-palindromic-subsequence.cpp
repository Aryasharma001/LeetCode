//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int f (int i, int j, string A, string rev, vector<vector<int>>& dp){

    if(i<0 || j<0)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(A[i] == rev[j])
        return dp[i][j] = 1 + f (i-1, j-1, A, rev, dp);
    
    else 
        return dp[i][j] = max(f(i, j-1, A, rev, dp), f(i-1, j, A, rev, dp));
}


int longestPalinSubseq(string A) {
    
    int n=A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(n - 1, n - 1, A, rev, dp);
}
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends