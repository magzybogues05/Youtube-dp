class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<pair<int,int>> adj[V+1];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dist(V+1, INT_MAX);
        vector<int> ways(V+1, 0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int u = it.second;
            
            if (d > dist[u])
            {
                continue;
            }
            
            for (auto curr : adj[u]) {
                int v=curr.first;
                int wt=curr.second;
                long long newDist = d + wt;
                
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                }
                else if (newDist == dist[v]) {
                    ways[v] = ways[v] + ways[u];
                }
            }
        }
        
        return ways[V - 1];
    }
};