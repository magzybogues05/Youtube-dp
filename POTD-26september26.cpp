class Solution {
  public:
  
    int dp[501];
    int solve(int x, int s, int m, int l, int cs, int cm, int cl) 
    {
        if (x <= 0)
        {
            return 0;
        }
        if(dp[x] != -1) 
        {
            return dp[x];
        }
        int ans = cs + solve(x - s, s, m, l, cs, cm , cl);
        ans = min(ans, cm + solve(x - m, s, m, l, cs, cm, cl));
        ans = min(ans, cl + solve(x - l, s, m, l, cs, cm, cl));
        return dp[x] = ans;
    }

  
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        
        memset(dp,-1,sizeof dp);
        return solve(x, s, m, l, cs, cm, cl);
    }
};