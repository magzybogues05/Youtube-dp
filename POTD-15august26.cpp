class Solution {
  public:
    int dp[11][2][2];
    int solve(int idx, int tight, int started, string &s, int d) 
    {
        if (idx == s.size())
        {
            return 1;
        }

        if (dp[idx][tight][started]!=-1)
        {
            return dp[idx][tight][started];
        }

        int ans = 0;

        int limit = 9;
        if(tight)
        {
            limit=(s[idx]-'0');
        }

        for (int i = 0; i <= limit; i++) 
        {
            int ntight = tight && (i == limit);
            int nstarted = started || (i != 0);

            if (nstarted && i == d)
            {
                continue;
            }
            ans += solve(idx + 1, ntight, nstarted, s, d);
        }

        return dp[idx][tight][started] = ans;
    }
    
    int countWithout(int n, int d) {
        // code here
        memset(dp,-1,sizeof dp);
        string s=to_string(n);
        return solve(0,1,0,s,d) - 1;
    }
};