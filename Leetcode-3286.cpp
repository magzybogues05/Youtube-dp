class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>d{0,1,0,-1,0};
        vector<vector<int>>cost(n,vector<int>(m,INT_MIN));
        cost[0][0]=health-grid[0][0];
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({cost[0][0],{0,0}});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            if(it.first<1)
            {
                break;
            }
            if(it.second.first==n-1 && it.second.second==m-1)
            {
                return true;
            }
            for(int t=0;t<4;t++)
            {
                int ni=it.second.first+d[t];
                int nj=it.second.second+d[t+1];
                if(ni>=0 && ni<n && nj>=0 && nj<m)
                {
                    int val=it.first-grid[ni][nj];
                    if(val>cost[ni][nj])
                    {
                        cost[ni][nj]=val;
                        pq.push({val,{ni,nj}});
                    }
                }
            }
        }
        return false;
    }
};