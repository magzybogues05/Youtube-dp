class Solution {
public:
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>arr(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    arr[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int>da{0,0,-1,1};
        vector<int>db{1,-1,0,0};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(int t=0;t<4;t++)
            {
                int ni=it.first+da[t];
                int nj=it.second+db[t];
                if(ni>=0 && nj>=0 && ni<n && nj<n && vis[ni][nj]==-1 && arr[it.first][it.second]+1<arr[ni][nj])
                {
                    vis[ni][nj]=1;
                    arr[ni][nj]=arr[it.first][it.second]+1;
                    q.push({ni,nj});
                }
            }
        }
        
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>> dist(n,vector<int>(n, INT_MIN));

        dist[0][0] = arr[0][0];
        pq.push({arr[0][0],{0,0}});
        
         while (!pq.empty())
        {
            int i = pq.top().second.first;
            int j=pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            for(int t=0;t<4;t++)
            {
                int ni=i+da[t];
                int nj=j+db[t];
                if(ni>=0 && nj>=0 && ni<n && nj<n)
                {
                    int w=arr[ni][nj];
                    if(min(w,dis)>dist[ni][nj])
                    {
                        dist[ni][nj]=min(w,dis);
                        pq.push({min(w,dis),{ni,nj}});
                    }
                }
            }
            
        }
        return dist[n-1][n-1];
        
    }
};