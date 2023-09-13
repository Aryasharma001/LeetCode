//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S==0 && N==1)
        return "0";
        if (S < 1 || S > 9 * N) {
            return "-1"; 
        }
        vector<int>ans;
        for(int i=1;i<=N;i++){
            int a=min(9,S);
            ans.push_back(a);
            S=S-a;
        }
        string an="";
        for(int i=0;i<N;i++){
            an+=to_string(ans[i]);
        }
        return an;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends