//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int f(int n){
        unsigned int count=0;
        while(n!=0){
            count++;
            if(n%2!=0)
            return count;
            n=n/2;
        }
        return count;
    }
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        return f(n);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends