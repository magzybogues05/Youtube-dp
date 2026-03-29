class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        
        int sum = 0;
        for (int x : arr)
        {
            sum += x;
        }
        
        int total=sum+diff;
        if (total < 0 || (total%2 != 0))
        {
            return 0;
        }
        
        int target = total / 2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int num : arr) {
            for (int s = target; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }
        
        return dp[target];
    }
};