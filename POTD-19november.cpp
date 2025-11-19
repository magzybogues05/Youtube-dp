class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>mineffort(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<int>da{-1,1,0,0};
        vector<int>db{0,0,-1,1};
        pq.push({0,{0,0}});
        mineffort[0][0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1)
            {
                return it.first;
            }
            for(int i=0;i<4;i++)
            {
                int nr=r+da[i];
                int nc=c+db[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m)
                {
                    int currdiff=abs(mat[nr][nc]-mat[r][c]);
                    if(max(it.first,currdiff)<mineffort[nr][nc])
                    {
                        mineffort[nr][nc]=max(it.first,currdiff);
                        pq.push({mineffort[nr][nc],{nr,nc}});
                    }
                }
            }
            
        }
        return -1;
    }
};
