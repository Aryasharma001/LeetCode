class Solution {
public:
   bool bfs(int node,vector<vector<int>>adj,vector<int>&vis,vector<int>&crcvis){
       vis[node]=1;
       crcvis[node]=1;
       for(auto it:adj[node]){
           if(!vis[it]){
               if(bfs(it,adj,vis,crcvis)) return true;
           }
           else if(vis[it] && crcvis[it]){
                   return true;
           }
       }
       crcvis[node]=0;
       return false;
       
   }
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n = numCourses;   
        vector<vector<int>>adj(n);
       for(int i=0;i<prerequisites.size();i++){
           int u=prerequisites[i][0];
           int v=prerequisites[i][1];
           adj[u].push_back(v);
       }
       vector<int>vis(n,0);
       vector<int>crcvis(n,0);
       for(int i=0;i<n;i++){
           if(!vis[i]){
               if(bfs(i,adj,vis,crcvis))
               return false;
       }
       }
       return true;
       
   }

};
