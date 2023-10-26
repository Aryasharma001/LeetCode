class Solution {
public:
    
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> q;
    int cnt = 0;
    int V = numCourses; // Use numCourses as the number of vertices
    vector<int> indegree(V, 0);
    vector<vector<int>> adj(V);

    for (int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u); // Reversed the direction of the edge
        indegree[u]++;
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If cnt is not equal to V, there is a cycle, and you cannot finish the courses.
    return cnt == V;
}

};
