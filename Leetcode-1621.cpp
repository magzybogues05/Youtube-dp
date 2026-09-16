#define ll long long int
#define mod 1000000007
class Solution {
public:
    int numberOfSets(int n, int k) {

        vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
        
        for(int i = 0; i < n; i++) 
        {
            dp[i][0] = 1;
        }

        for(int j = 1; j <= k; j++) 
        {
            
            ll sum = 0;
            for(int i = 1; i < n; i++) 
            {
                
                sum = (sum + dp[i-1][j-1]) % mod;

                dp[i][j] = dp[i-1][j];
                dp[i][j] = (dp[i][j] + sum) % mod;
            }
        }

        return dp[n-1][k];
    }
};