class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
    
        if (V == 1)
        {
            return {0};
        }
        
        vector<int> adj[V+1];
        vector<int> degree(V, 0);
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        int remaining = V;
        
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            
            for (int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                for (int u: adj[it]) {
                    degree[u]--;
                    if (degree[u] == 1) {
                        q.push(u);
                    }
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};