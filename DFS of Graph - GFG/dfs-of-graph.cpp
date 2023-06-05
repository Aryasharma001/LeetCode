//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void dfs(int node,vector<int> &visited,vector<int> adj[],vector<int> &ans)
   {
       visited[node] = 1;
       ans.push_back(node);
       for(auto val: adj[node])
       {
           if(visited[val]!=1)
            dfs(val,visited,adj,ans);
       }
   }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         vector<int> visited(V+1,0);
         vector<int> ans;
         dfs(0,visited,adj,ans);
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends