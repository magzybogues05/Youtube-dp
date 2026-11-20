class Solution {
public:
    int maxSelectedElements(vector<int>& arr) {
        map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        vector<int>nums;
        for(auto it:mp)
        {
            if(it.second>=2)
            {
                nums.push_back(it.first);
                nums.push_back(it.first);
            }
            else{
                nums.push_back(it.first);
            }
        }
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                if(nums[i]==(nums[i-1]+1))
                {
                    dp[i][0]=1+dp[i-1][0];
                }
                if(nums[i]==nums[i-1])
                {
                    dp[i][0]=max(dp[i][0],dp[i-1][0]);
                }
                if((nums[i]==(nums[i-1]+2)) && (i>=1))
                {
                    dp[i][0]=max(dp[i][0],(1+dp[i-1][1]));
                }
                
            }
            else{
                dp[i][0]=1;
            }
            if(i>0)
            {
                if(nums[i-1]==nums[i])
                {
                    dp[i][1]=1+dp[i-1][0];
                }
                if(nums[i-1]==(nums[i]-1))
                {
                    dp[i][1]=max(dp[i][1],(1+dp[i-1][1]));
                }
            }
            
            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};