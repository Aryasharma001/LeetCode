//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
string FirstNonRepeating(string A){
    // Code here
    vector<int> v(26,INT_MAX);
    string ans = "";
    int p = 0;
    vector<int> v2(26,0);
    for(int i = 0;i<A.length();i++){
      if(v[A[i]-'a']!=INT_MAX && v2[A[i]-'a']==0) {
          v[A[i]-'a'] = INT_MAX;
          v2[A[i]-'a']=1;
      }
      else if(v2[A[i]-'a']==0){
          v[A[i]-'a'] = INT_MIN + p;
          p+=1;
      }
      int mini = INT_MAX;
      int k=-1;
      for(int j = 0;j<26;j++){
          if(v[j]<mini){
              mini = v[j];
              k = j;
          }
      }
      if(k==-1) ans.push_back('#');
      else ans.push_back('a'+k);
    }
    return ans;
}
 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends