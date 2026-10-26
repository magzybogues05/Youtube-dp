class Solution {
public:

    void solve(int i,int j,vector<vector<int>>&grid,int k,int &sum,vector<int>&da,vector<int>&db)
    {
        int n=grid.size();
        int m=grid[0].size();
        sum= (sum+grid[i][j])%k;
        grid[i][j]=0;
        for(int d=0;d<4;d++)
        {
            int ni=i+da[d];
            int nj=j+db[d];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=0)
            {
                solve(ni,nj,grid,k,sum,da,db);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();

        vector<int>da{0,0,1,-1};
        vector<int>db{1,-1,0,0};
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    int sum=0;
                    solve(i,j,grid,k,sum,da,db);
                    if(sum%k==0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};