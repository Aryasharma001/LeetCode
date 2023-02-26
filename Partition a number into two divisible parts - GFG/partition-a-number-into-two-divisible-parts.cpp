//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
    string ans,p;
    for(int i=1;i<S.size();i++){
        ans=S.substr(0,i);
        p=S.substr(i,S.size());
        if(stoi(ans)%a==0 && stoi(p)%b==0){
            return ans+" "+p;
        }
    }
    return "-1";
}

};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
} 
// } Driver Code Ends