//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    vector<int> hsh(1000001, 0);
    vector<int> hsh2(1000001, 0);
    for(int i=0;i<n;i++){
        hsh[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        hsh2[a2[i]]++;
    }
    for(int i=0;i<1000001;i++){
        if(hsh2[i]>0 && hsh2[i]>hsh[i])
        {
            return "No";
        }
    }
    return "Yes";
}
