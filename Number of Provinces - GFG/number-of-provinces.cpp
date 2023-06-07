//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  void dfs(int i,vector<int > adjlist[],vector<int> &vis){
      vis[i]=1;
      for(auto x:adjlist[i]){
          if(!vis[x])
          dfs(x,adjlist,vis);
      }
      
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjlist[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
                
            }
        }
            int cnt=0;
            vector<int>vis(V+1,0);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,adjlist,vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends