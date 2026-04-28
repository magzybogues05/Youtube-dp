class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size(), n = grid[0].size();
            int total = m * n, left = grid[0][0] % x;
            int mini = grid[0][0], maxi = grid[0][0];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] % x != left) {
                        return -1;
                    }
                    mini = min(mini, grid[i][j]);
                    maxi = max(maxi, grid[i][j]);
                }
            }

            int k = total / 2 , low = mini , high = maxi , median = low;        
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int count = 0;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] <= mid)
                        {
                            count++;
                        }
                    }
                }

                if (count <= k) {
                    low = mid + 1;
                }
                else {
                    median = mid;
                    high = mid - 1;
                }
            }            

            long long ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    ans += abs(grid[i][j] - median) / x;
                }
            }
            return ans;
        }
};