//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfscheck(int i,vector<int> adj[],int vis[],int pathvis[]){
        vis[i]=1;
        pathvis[i]=1;
        
        //traverse for adjacent nodes
        for(auto it:adj[i]){
            // when the node is not visited
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis)==true) return true;
            }
            //if the node has been previously visited, but it has to be visited to be on same path
            else if(pathvis[it])
            return true;
        }
        pathvis[i]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=1;i<V;i++){
            if(!vis[i]){
                if(dfscheck(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends