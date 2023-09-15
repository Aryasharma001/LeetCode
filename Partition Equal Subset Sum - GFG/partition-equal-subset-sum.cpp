//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution {
public:
    bool f(int i, int sum, int N, int arr[], vector<vector<int>>& dp) {
        if (sum == 0)
            return true;
        if (sum < 0 || i == N)
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        // Explore both cases: include the current element or exclude it
        bool include = f(i + 1, sum - arr[i], N, arr, dp);
        bool exclude = f(i + 1, sum, N, arr, dp);

        return dp[i][sum] = include || exclude;
    }

    int equalPartition(int N, int arr[]) {
        int totalSum = 0;
        for (int i = 0; i < N; i++) {
            totalSum += arr[i];
        }

        // If the total sum is odd, it can't be divided into equal partitions
        if (totalSum % 2 != 0) {
            return 0;
        }

        // Initialize the dp array with -1 values
        vector<vector<int>> dp(N, vector<int>(totalSum / 2 + 1, -1));

        // Check if there's a subset with a sum equal to totalSum/2
        return f(0, totalSum / 2, N, arr, dp) ? 1 : 0;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends