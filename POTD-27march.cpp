class Solution
{
public:
    int findShortestPath(vector<vector<int>> &matt)
    {
        int n=matt.size();
        int m=matt[0].size();
        vector<vector<int>>mat=matt;
        vector<int>na{0,0,-1,1};
        vector<int>nb{1,-1,0,0};
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               for(int k=0;k<4;k++)
               {
                   int ni=i+na[k];
                   int nj=j+nb[k];
                   if(ni>=0 && nj>=0 && ni<n && nj<m && matt[ni][nj]==0)
                   {
                        mat[i][j]=0;
                   }
               }
           }
       }
       vector<vector<int>>vis(n,vector<int>(m,-1));
       queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<n;i++)
       {
           if(mat[i][0]==1){
               q.push({{i,0},1});
               vis[i][0]=1;
            //   cout<<"hee"<<endl;
           }
       }
       while(!q.empty())
       {
           auto it=q.front();
           q.pop();
           int i=it.first.first;
           int j=it.first.second;
           if(j==m-1)
           {
               return it.second;
           }
           for(int k=0;k<4;k++)
           {
                    int ni=i+na[k];
                   int nj=j+nb[k];
                   if(ni>=0 && nj>=0 && ni<n && nj<m && mat[ni][nj]==1 && vis[ni][nj]==-1)
                   {
                        vis[ni][nj]=1;
                        q.push({{ni,nj},it.second+1});
                   }
           }
       }
       return -1;
    }
};