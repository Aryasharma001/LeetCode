//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void dfs1(vector<int> adj[], int node, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(adj, it, vis, st);
            }
        }
        st.push(node);
    }

    void dfs2(vector<int> adj[], int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs2(adj, it, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(adj, i, vis, st);
            }
        }

        fill(vis.begin(), vis.end(), 0);
        int last_vertex = st.top();
        dfs2(adj, last_vertex, vis);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                return -1; // No mother vertex found
            }
        }

        return last_vertex;
    }



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends