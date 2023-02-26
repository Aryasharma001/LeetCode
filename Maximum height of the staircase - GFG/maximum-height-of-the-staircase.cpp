//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxStairHeight(int N) {
        // Code here
        int ans=0;
        int i=0;
        int count=0;
        while(ans<=N){
            ans=(i*(i+1))/2;
            count=max(count,i);
            i++;
            
        }
        return count-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.maxStairHeight(N) << endl;
    }
    return 0;
}
// } Driver Code Ends