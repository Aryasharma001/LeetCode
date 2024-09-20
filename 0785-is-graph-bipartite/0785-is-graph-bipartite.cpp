class Solution {
public:
     bool bipartite(vector<vector<int>>graph,vector<int>color,int start) {
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(bipartite(graph,color,i)==false)
                    return false;
            }
        }
        return true;
    }
};