class Solution {
  public:
    vector<int>dis={0,1,0,-1,0};
    void dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;
        int n=mat.size();
        int m=mat[0].size();

        for (int d=0;d<4;d++) {
            int ni = i + dis[d];
            int nj = j + dis[d+1];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
            {
                continue;
            }

            if (vis[ni][nj])
            {
                continue;
            }
            
            if (mat[ni][nj] >= mat[i][j])
            {
                dfs(ni, nj, mat, vis);
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> stationP(n, vector<bool>(m, false));
        vector<vector<bool>> stationQ(n, vector<bool>(m, false));

        for (int j = 0; j < m; j++)
        {
            if (!stationP[0][j])
            {
                dfs(0, j, mat, stationP);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!stationP[i][0])
            {
                dfs(i, 0, mat, stationP);
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (!stationQ[n - 1][j])
            {
                dfs(n - 1, j, mat, stationQ);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!stationQ[i][m - 1])
            {
                dfs(i, m - 1, mat, stationQ);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (stationP[i][j] && stationQ[i][j])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};