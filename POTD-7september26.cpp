class Solution {
  public:
  
    int dp[101][102][102];
    int solve(int i, int lastInc, int lastDec, vector<int>&arr)
    {
        int n=arr.size();
        if(i==n)
        {
            return 0;
        }
        if (dp[i][lastInc][lastDec] != -1)
        {
            return dp[i][lastInc][lastDec];
        }

        int ans = solve(i + 1, lastInc, lastDec, arr);

        if (lastInc == n || arr[i] > arr[lastInc]) 
        {
            ans = max(ans, 1 + solve(i + 1, i, lastDec, arr));
        }

        if (lastDec == n || arr[i] < arr[lastDec]) 
        {
            ans = max(ans, 1 + solve(i + 1, lastInc, i, arr));
        }

        return dp[i][lastInc][lastDec] = ans;
    }

  
    int minCount(vector<int>& arr) {
        // code here
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return n - solve(0,n,n,arr);
    }
};