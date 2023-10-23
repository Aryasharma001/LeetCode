//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int index,vector<int>adj[],vector<int>&vis,vector<int>&ls){
        vis[index]=1;
        ls.push_back(index);
        for(auto it:adj[index]){
            if(!vis[it])
            dfs(it,adj,vis,ls);
            
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        // Code here
        vector<int>vis(V,0);
        vector<int>ls;
        dfs(0,adj,vis,ls);
        return ls;
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