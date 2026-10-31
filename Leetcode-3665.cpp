#define mod 1000000007
class Solution {
public:
    int dp[501][501][3];
    int solve(int i,int j,int last,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        if(i==n-1 && j==m-1)
        {
            return 1;
        }

        if(i==n || j==m)
        {
            return 0;
        }

        if(dp[i][j][last+1]!=-1)
        {
            return dp[i][j][last+1];
        }

        int ans=0;
        if(grid[i][j]==0)
        {
            ans=(solve(i,j+1,0,grid)%mod + solve(i+1,j,1,grid)%mod)%mod;
        }
        else{
            if(last==0)
            {
                ans=solve(i+1,j,1,grid);
            }
            else{
                ans=solve(i,j+1,0,grid);
            }
        }
        return dp[i][j][last+1]=ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,-1,grid);
    }
};