#define ll long long int
#define mod 1000000007
class Solution {
  public:
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();

        vector<ll> dp(m + 1, 0);
        dp[0] = 1;
        for (int i=1;i<=n;i++) 
        {
            for (int j=m;j>=1;j--) 
            {
                if (s1[i-1] == s2[j-1]) 
                {
                    dp[j] = (dp[j] + dp[j-1]) % mod;
                }
            }
        }
        return dp[m];
    }
};