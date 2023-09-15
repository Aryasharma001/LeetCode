//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
     long long m=1e9+7;
    long long ways(int step,vector<long long>&dp){
        if(step==0)
        return 1;
        if(step==1||step==2){
            return step;
        }
    
        if(dp[step]!=-1)
        return dp[step];
        
        return dp[step]=(ways(step-1,dp)+ways(step-2,dp)+ways(step-3,dp))%m;
        
        
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long>dp(n+1,-1);
        return ways(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends