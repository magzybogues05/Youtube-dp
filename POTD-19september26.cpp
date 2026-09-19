class Solution {
  public:
    
    int dp[1001][1001];
    
    int solve(int i, int j, string &s1, string &s2, int costA, int costB) 
    {
            int n=s1.size();
            int m=s2.size();
            if ((i == n) || (j == m))
            {
                return (n-i)*costA + (m-j)*costB;
            }

            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }

            if (s1[i] == s2[j]) 
            {
                return dp[i][j] = solve(i+1, j+1, s1, s2, costA, costB);
            }

            return dp[i][j] = min(
                costA + solve(i+1, j, s1, s2, costA, costB),
                costB + solve(i, j+1, s1, s2, costA, costB)
            );
        }
  
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(0,0,s1,s2,costS1,costS2);
    }
};