int dp[50001];
class Solution {
public:

    int solve(int i,vector<int>&stones)
    {
        int n=stones.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i] != -1) 
        {
            return dp[i];
        }
        int ans=INT_MIN;
        int curr=0;
        for(int j=i;j<min(n,i+3);j++)
        {
            curr+=stones[j];
            int val=solve(j+1,stones);
            ans=max(ans,curr-val);
        }
        return dp[i]=ans;

    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int diff=solve(0,stoneValue);
        if(diff>0)
        {
            return "Alice";
        }
        else if(diff<0)
        {
            return "Bob";
        }
        return "Tie";
    }
};