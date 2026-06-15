class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
    
        int n = cost.size();
    
        for (int i = 0; i < n; i++) 
        {
            if (cost[i] == -1)
            {
                continue;
            }
            int wt = i + 1;
            for (int cur = wt; cur <= w; cur++) 
            {
                if(dp[cur-wt]!=INT_MAX)
                {
                    dp[cur] = min(dp[cur],dp[cur-wt]+cost[i]);
                }
            }
        }
        if(dp[w]==INT_MAX)
        {
            return -1;
        }
        return dp[w];
    }
};