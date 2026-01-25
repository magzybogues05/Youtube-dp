class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n%2!=0)
        {
            return 0;
        }
        n/=2;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int in=0;
            int out=i-1;
            while(in<i)
            {
                dp[i]+=(dp[in]*dp[out]);
                in++;
                out--;
            }
        }
        return dp[n];
    }
};