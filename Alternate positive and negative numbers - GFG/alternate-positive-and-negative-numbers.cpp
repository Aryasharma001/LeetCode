//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	   vector<int> pos;
	   vector<int> neg;
	   for(int i=0;i<n;i++){
	       if(arr[i]>=0)
	       pos.push_back(arr[i]);
	       else
	       neg.push_back(arr[i]);
	   }
	   int m=pos.size();
	   int ni=neg.size();
	   int s=max(m,ni);
	   vector<int>ans;
	   int negi=0,posi=0;
	   while(posi<m || negi<ni){
	       if(posi<m){
	           ans.push_back(pos[posi]);
	           posi++;
	       }
	       if(negi<ni){
	           ans.push_back(neg[negi]);
	           negi++;
	       }
	   }
	   //for(auto it:ans){
	     //  cout<<it<<" ";
	   //}
	   //cout<<endl;
	   for(int i=0;i<n;i++){
	       arr[i]=ans[i];
	   }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends