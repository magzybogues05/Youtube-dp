class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int k, int c,vector<vector<vector<int>>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m || j == n)
        {
            return INT_MIN;
        }

        if(dp[i][j][c] != -1)
        {
            return dp[i][j][c];
        }
        int score = 0;
        int cost = 0;
        if(grid[i][j] == 1)
        {
            score += 1;
            cost += 1;
        }
        else if(grid[i][j] == 2)
        {
            score += 2;
            cost += 1;
        }
        if(c+cost > k)
        {
            return dp[i][j][c] = INT_MIN;
        }
        if(i == m-1 && j == n-1)
        {
            return dp[i][j][c] = score;
        }
        int right = solve(i,j+1,grid,k,c+cost,dp);
        int down = solve(i+1,j,grid,k,c+cost,dp);
        int best = max(right,down);
        if(best != INT_MIN)
        {
            best+=score;
        }
        return dp[i][j][c] = best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (k+1,-1)));
        int ans = solve(0,0,grid,k,0,dp);
        return (ans == INT_MIN)? -1 : ans;
    }
};