//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count = 0;
        for(int i = 0 ; i < n  ; i ++)
        {   long prod=a[i];
        if(prod<k)count++;
            for(int j = i+1 ; j < n ; j ++)
            { 
              prod*=a[j]; 
              if(prod<k)count++;
              else break;
              
            }
        }
        return count;
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends