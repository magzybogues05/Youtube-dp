class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')')
        {
            return 0;
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m,0)));
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='(')
            {
                count++;
            }
            else{
                count--;
            }
            if(count<0)
            {
                break;
            }
            dp[i][0][count]=1;
        }
        count=0;
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]=='(')
            {
                count++;
            }
            else{
                count--;
            }
            if(count<0)
            {
                break;
            }
            dp[0][i][count]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[i][j]=='(')
                {
                    for(int k=1;k<(n+m);k++)
                    {
                        if(dp[i-1][j][k-1]==1 || dp[i][j-1][k-1]==1)
                        {
                            dp[i][j][k]=1;
                        }
                    }
                }
                else{
                    for(int k=0;k<(n+m-1);k++)
                    {
                        if(dp[i-1][j][k+1]==1 || dp[i][j-1][k+1]==1)
                        {
                            dp[i][j][k]=1;
                        }
                    }
                }
            }
        }
        return (dp[n-1][m-1][0]==1);
    }
};