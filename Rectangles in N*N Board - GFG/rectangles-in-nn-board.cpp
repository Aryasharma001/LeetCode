//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long rectanglesInChessBoard(long long N) {
        // code here
        long long n=N;
        long long smol=(n*n*(n+1)*(n+1))/4;
        long long large=(n*(n+1)*(2*n+1))/6;
        return (smol-large);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.rectanglesInChessBoard(N) << endl;
    }
    return 0;
}
// } Driver Code Ends