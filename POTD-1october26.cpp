class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n=duration.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &edge : dependencies) 
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> finishTime(n, 0);

        for (int i = 0; i < n; i++) 
        {
            if (indegree[i] == 0) 
            {
                q.push(i);
                finishTime[i] = duration[i];
            }
        }

        int completed = 0;
        int ans = 0;

        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();

            completed++;
            ans = max(ans, finishTime[u]);

            for (int v : adj[u]) 
            {
                finishTime[v] = max(
                    finishTime[v],
                    finishTime[u] + duration[v]
                );

                indegree[v]--;

                if (indegree[v] == 0) 
                {
                    q.push(v);
                }
            }
        }

        if (completed != n)
        {
            return -1;
        }

        return ans;
    }
};