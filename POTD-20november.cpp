class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        int n=s.size();
        vector<vector<int>>mincost(26,vector<int>(26,INT_MAX));
        
        for(int i=0;i<transform.size();i++)
        {
            auto it=transform[i];
            mincost[(it[0]-'a')][(it[1]-'a')]= min(mincost[(it[0]-'a')][(it[1]-'a')],cost[i]);
        }
        for(int i=0;i<26;i++)
        {
            mincost[i][i]=0;
        }
        
        
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    if(mincost[i][k]!=INT_MAX && mincost[k][j]!=INT_MAX)
                    {
                        mincost[i][j]=min(mincost[i][j],mincost[i][k]+mincost[k][j]);
                    }
                }
            }
        }
        
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            int a=(s[i]-'a');
            int b=(t[i]-'a');
            int temp=INT_MAX;
            for(int ch=0;ch<26;ch++)
            {
                if(mincost[a][ch]!=INT_MAX && mincost[b][ch]!=INT_MAX)
                {
                    temp=min(temp,mincost[a][ch]+mincost[b][ch]);
                }
            }
            if(temp==INT_MAX)
            {
                return -1;
            }
            ans+=temp;
        }
        return ans;
    }
};