#define ll long long int 
#define mod 1000000007
class Solution {
  public:
  
    vector<int> solve(vector<vector<int>>& grid, int i, int j, vector<vector<vector<int>>>&dp) {
        int n=grid.size();
        if (i >= n || j >= n)
        {
            return {0, 0};
        }

        if ((i == n - 1) && (j == n - 1))
        {
            return {1, grid[i][j]};
        }

        if (!dp[i][j].empty())
        {
            return dp[i][j];
        }

        vector<int> ans(2, 0);

        if (grid[i][j] == 1) 
        {
            vector<int> right = solve(grid, i, j + 1, dp);
            if (right[0])
            {
                ans[0] = right[0];
                ans[1] = right[1] + grid[i][j];
            }
        }
        else if (grid[i][j] == 2) 
        {
            vector<int> down = solve(grid, i + 1, j, dp);
            if (down[0]) 
            {
                ans[0] = down[0];
                ans[1] = down[1] + grid[i][j];
            }
        } 
        else 
        {
            vector<int> right = solve(grid, i, j + 1, dp);
            vector<int> down = solve(grid, i + 1, j, dp);
            if (right[0]) 
            {
                ans[0] = right[0];
                ans[1] = right[1] + grid[i][j];
            }
            if (down[0]) 
            {
                ans[0] = (ans[0] + down[0]) % mod;
                ans[1] = max(ans[1], down[1] + grid[i][j]);
            }
        }

        return dp[i][j] = ans;
    }
  
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1));
        return solve(grid, 0, 0, dp);
    }
};