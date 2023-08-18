//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> prefixSum; // Map to store prefix sum and its index
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i];
            
            // If sum is 0, update maxLength
            if (sum == 0) {
                maxLength = i + 1;
            }
            
            // If sum is already present in prefixSum, update maxLength
            if (prefixSum.find(sum) != prefixSum.end()) {
                maxLength = max(maxLength, i - prefixSum[sum]);
            } else {
                // Store the index of the first occurrence of the sum
                prefixSum[sum] = i;
            }
        }

        return maxLength;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends