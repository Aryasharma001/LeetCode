//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool>visited(V,false);
        queue<int>q;
        q.push(0); // starting from 0th index;
        ans.push_back(0);
        visited[0]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int i=0;i<adj[front].size();i++){
                if(!visited[adj[front][i]]){
                    ans.push_back(adj[front][i]);
                    visited[adj[front][i]]=true;
                    q.push(adj[front][i]);
                }
            }
        }
        return ans;
    }
};

  


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends