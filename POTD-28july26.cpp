class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
       int newNodes = 0;

        vector<vector<int>> adj(V + edges.size());

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                int x = V + newNodes;
                newNodes++;

                adj[u].push_back(x);
                adj[x].push_back(u);

                adj[x].push_back(v);
                adj[v].push_back(x);
            }
        }

        vector<int> dist(V + newNodes, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            if (u == dest)
            {
                return dist[u];
            }

            for (int v : adj[u]) 
            {
                if (dist[v] == -1) 
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};