#define mod 1000000007
class Solution {
  public:
    int dp[2][1001][1001];
    int solve(int i,int count,int prev,int n,int k)
    {
        if (count > k)
        {
            return 0;
        }

        if (i == n)
        {
            return (count == k);
        }

        if (dp[prev][i][count] != -1)
        {
            return dp[prev][i][count];
        }

        int ans = solve(i+1,count,0,n,k);
        ans = (ans%mod + solve(i+1,count+(prev == 1),1,n,k)%mod)%mod;
        return dp[prev][i][count]=ans;
    }
    int countStrings(int n, int k) {
        // code here
        memset(dp,-1,sizeof dp);
        int ans=solve(1,0,0,n,k);
        ans=(ans%mod+solve(1,0,1,n,k)%mod)%mod;
        return ans;
    }
};