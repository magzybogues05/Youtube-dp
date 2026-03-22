class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        vector<int>da{1,-1,0,0};
        vector<int>db{0,0,1,-1};
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int size=q.size();
            while(size--)
            {
                auto curr=q.front();
                q.pop();
                mat[curr.first][curr.second]=2;
                for(int t=0;t<4;t++)
                {
                    int ni=curr.first+da[t];
                    int nj=curr.second+db[t];
                    if(ni>=0 && nj>=0 && ni<mat.size() && nj<mat[0].size() && vis[ni][nj]==-1 && mat[ni][nj]==1)
                    {
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return max(0,ans-1);
    }
};