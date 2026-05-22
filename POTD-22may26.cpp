class Solution {
  public:
  
    void dfs(int i,int j,vector<vector<int>>&grid,vector<int>&di,vector<int>&dj)
    {
        int n=grid.size();
        int m=grid[0].size();
        grid[i][j]=0;
        for(int d=0;d<4;d++)
        {
            int ni=i+di[d];
            int nj=j+dj[d];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1)
            {
                dfs(ni,nj,grid,di,dj);
            }
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>di{0,0,1,-1};
        vector<int>dj{1,-1,0,0};
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0,grid,di,dj);
            }
            if(grid[i][m-1]==1)
            {
                dfs(i,m-1,grid,di,dj);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                dfs(0,j,grid,di,dj);
            }
            if(grid[n-1][j]==1)
            {
                dfs(n-1,j,grid,di,dj);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};