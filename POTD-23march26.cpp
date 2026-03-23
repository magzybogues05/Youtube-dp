class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> out(V, -1);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            out[u] = v;
        }
        
        vector<int> visited(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;

            unordered_map<int, int> stepMap;
            int node = i;
            int step = 0;

            while (node != -1 && !visited[node]) {
                visited[node] = 1;
                stepMap[node] = step++;

                node = out[node];

                if (node != -1 && stepMap.count(node)) {
                    int cycleLength = step - stepMap[node];
                    ans = max(ans, cycleLength);
                    break;
                }
            }
        }

        return ans;

    }
};
