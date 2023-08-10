//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int n = mat.size();
        int m = mat[0].size();
        
        for (int i = 0; i < n; i++) {
            int start = 0, end = m - 1;
            
            while (start <= end) {
                int mid = start + (end - start) / 2;
                
                if (mat[i][mid] == X) {
                    return true;
                } else if (mat[i][mid] < X) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return false;
    }
	    
	
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends