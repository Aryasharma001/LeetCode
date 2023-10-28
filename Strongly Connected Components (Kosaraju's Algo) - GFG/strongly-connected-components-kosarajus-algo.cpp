//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(stack<int>&s,vector<vector<int>>& adj,vector<bool>&vis,int node){
	    
	    vis[node]=true;
	    for(auto it:adj[node]){
	        if(!vis[it])
	        dfs(s,adj,vis,it);
	    }
	    s.push(node);
	}
	
	void dfs2(vector<vector<int>>& adj2,vector<bool>&vis2,int node){
	    vis2[node]=true;
	    for(auto it:adj2[node]){
	        if(!vis2[it]){
	            dfs2(adj2,vis2,it);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int>s;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(s,adj,vis,i);
            }
        }
        vector<vector<int>>adj2(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adj2[it].push_back(i);
           
            }
        }
        int cnt=0;
        vector<bool>vis2(V,false);
        //vector<int>temp;
        while(!s.empty()){
            //temp.push_back(s.top());
            int node=s.top();
            s.pop();
            if(!vis2[node]){
                dfs2(adj2,vis2,node);
                cnt++;
                
            }
            
        }
        return cnt;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends