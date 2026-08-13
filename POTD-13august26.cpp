class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) 
        {
            for (auto &[v, w] : adj[u]) 
            {
                indegree[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) 
        {
            if (indegree[i] == 0) 
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) 
            {
                indegree[v]--;
                if (indegree[v] == 0) 
                {
                    q.push(v);
                }
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        for (int u : topo) 
        {
            if (dist[u] == INT_MIN)
            {
                continue;
            }

            for (auto &[v, w] : adj[u]) 
            {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};