//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int>hash(27,0);
	    for(int i=0;i<pat.size();i++){
	        hash[int(pat[i]-'a')]++;
	    }
	    vector<int>temp(27,0);
	    for(int i=0;i<pat.size();i++){
	        temp[int(txt[i]-'a')]++;
	    }
	    int cnt=0;
	    if(hash==temp)
	    cnt++;
	    
	    for(int i=pat.size();i<txt.size();i++){
	       temp[int(txt[i]-'a')]++;
	       temp[int(txt[i-pat.size()]-'a')]--;
	       
	       if(temp==hash){
	           cnt++;
	       }
	        
	    }
	    return cnt;
	}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends