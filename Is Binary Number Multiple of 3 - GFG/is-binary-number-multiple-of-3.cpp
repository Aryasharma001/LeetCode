//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int isDivisible(string s) {
        int remainder = 0;
        for (int i = 0; i < s.size(); i++) {
            remainder = (remainder * 2 + (s[i] - '0')) % 3;
        }
        return (remainder == 0) ? 1 : 0;
    }
};


//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends