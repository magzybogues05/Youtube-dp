class Solution {
  public:
    int dp[10001];
    int solve(int n)
    {
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=n;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+solve(n-(i*i)));
        }
        return dp[n]=ans;
    }
    
    int minSquares(int n) {
        // Code here
        memset(dp,-1,sizeof dp);
        return solve(n);
        
    }
};