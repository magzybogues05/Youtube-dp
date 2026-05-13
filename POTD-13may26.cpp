class Solution {
  public:
  
    void dfs(int v, vector<int> adj[], vector<int> &vis) {
        vis[v] = 1;
        for (int u : adj[v]) {
            if (vis[u]==0) {
                dfs(u, adj, vis);
            }
        }
    }
  
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int>adj[V];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i]==0) {
                dfs(i, adj, vis);
                ans = i;
            }
        }

        fill(vis.begin(), vis.end(), 0);
        dfs(ans, adj, vis);

        for (int i=0;i<V;i++) {
            if (vis[i]==0)
            {
                return -1;
            }
        }

        return ans;
    }
};