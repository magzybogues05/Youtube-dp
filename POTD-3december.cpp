#define ll long long int
class Solution {
  public:
    ll dp[16][(1<<16)];
    ll solve(int i,ll mask,vector<vector<int>>&cost)
    {
        int n=cost.size();
        if(mask==(1<<n)-1)
        {
            if(i==0)
            {
                return 0;
            }
            return INT_MAX;
        }
        if(dp[i][mask]!=-1)
        {
            return dp[i][mask];
        }
        ll ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(!((mask>>j)&1))
            {
                ll temp=solve(j,(mask|(1LL<<j)),cost);
                if(temp!=INT_MAX)
                {
                    ans=min(ans,cost[i][j]+temp);
                }
            }
        }
        return dp[i][mask]=ans;
    }
    
    int tsp(vector<vector<int>>& cost) {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(0,0,cost);
        
    }
};