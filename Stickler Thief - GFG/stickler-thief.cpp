//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution {
public:
    // Function to find the maximum money the thief can get.
    int f(int arr[], int n, int i, vector<int>& dp) {
        // Base cases
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        // Calculate profit when the current house is robbed
        int take = f(arr, n, i + 2, dp)+arr[i];

        // Calculate profit when the current house is not robbed
        int not_take = f(arr, n, i + 1,dp);

        return dp[i] = max(take, not_take);
    }

    int FindMaxSum(int arr[], int n) {
        // Your code here
        if (n == 0) {
            return 0;
        }
        int profit = 0;
        vector<int> dp(n, -1);
        return f(arr, n, 0,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends