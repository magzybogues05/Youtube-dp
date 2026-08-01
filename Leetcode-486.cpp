class Solution {
public:
    int dp[21][21][2];
    int solve(int l,int r,vector<int>&nums,int turn)
    {
        if(l>r)
        {
            return 0;
        }
        if(dp[l][r][turn]!=-1)
        {
            return dp[l][r][turn];
        }
        if(turn==0)
        {
            return dp[l][r][turn]=max((nums[l]+solve(l+1,r,nums,1)),(nums[r]+solve(l,r-1,nums,1)));
        }
        return dp[l][r][turn]=min(solve(l+1,r,nums,0),solve(l,r-1,nums,0));
    }
    
    bool predictTheWinner(vector<int>& nums) {
        
        memset(dp,-1,sizeof dp);
        int sum=0;
        int n=nums.size();
        for(auto it:nums)
        {
            sum+=it;
        }
        int curr=solve(0,n-1,nums,0);
        return curr>=(sum-curr);
    }
};