class Solution {
  public:
    
    int dp[51][51];
    int solve(int faces, int dices, int sum){
        if(sum==0)
        {
            return (dices==0);
        }
        if(sum < 0 || dices==0)
        {
            return 0;
        }
        if(dp[dices][sum]!=-1)
        {
            return dp[dices][sum];
        }
        int ans = 0;
        for(int i=1;i<=faces;i++){
            ans += solve(faces, dices-1, sum - i);
        }
        return dp[dices][sum] = ans;
    }
  
    int noOfWays(int m, int n, int x) {
        memset(dp,-1,sizeof dp);
        return solve(m, n, x);
    }
};