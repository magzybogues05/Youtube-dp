class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) 
                {
                    if (len % d != 0)
                    {
                        continue;
                    }

                    int changes = 0;
                    for (int x = 0; x < d; x++) 
                    {
                        int l = i + x;
                        int r = i + x + ((len - (x + 1)) / d) * d;

                        while (l < r) 
                        {
                            if (s[l] != s[r])
                            {
                                changes++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= k; j++) 
            {
                for (int p = 0; p < i; p++) 
                {
                    if (i - p < 2)
                    {
                        continue;
                    }

                    if (dp[p][j - 1] == INT_MAX)
                    {
                        continue;
                    }

                    dp[i][j] = min(dp[i][j],dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};