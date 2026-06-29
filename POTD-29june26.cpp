#define ll long long int
class Solution {
  public:
    ll dp[1001][1001];
    ll solve(int i, int j, vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        if (j == m)
        {
            return 0;
        }

        if (i == n)
        {
            return LLONG_MIN;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        ll skip = solve(i + 1, j, a, b);
        ll take = solve(i + 1, j + 1, a, b);
        if (take != LLONG_MIN)
        {
            take += a[i]*1LL*b[j];
        }

        return dp[i][j] = max(skip, take);
    }
  
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(0, 0, a, b);
    }
};