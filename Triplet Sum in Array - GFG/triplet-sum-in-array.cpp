//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int sum;
        sort(A,A+n);
        for(int i=0;i<n;i++){
            int x=X-A[i];
            int j=i+1,k=n-1;
            while(j<k){
                    sum=A[j]+A[k];
                    if(sum==x)
                    return true;
                    if(sum>x)
                    k--;
                    if(sum<x)
                    j++;
                    
            }
            
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int j,A[n];
		for(j=0;j<n;j++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code End
