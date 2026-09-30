#define mod 1000000007
class Solution {
  public:
    int ways(int x, int y) {
        // code here

        vector<vector<long long>>dp(x+1,vector<long long>(y+1,0));

        dp[0][0] = 1;

        for (int i = 0; i <= x; i++) 
        {
            for (int j = 0; j <= y; j++) 
            {

                if (i > 0)
                {
                    dp[i][j] = (dp[i][j]%mod + dp[i - 1][j]%mod)%mod;
                }

                if (j > 0)
                {
                    dp[i][j] = (dp[i][j]%mod + dp[i][j - 1]%mod)%mod;
                }
                
            }
        }

        return dp[x][y];
    }
};