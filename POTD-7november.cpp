class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(),jobs.end(),[&](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        
        vector<int>end;
        for(auto it:jobs)
        {
            end.push_back(it[1]);
        }
        
        int n=jobs.size();
        vector<int>dp(n,0);
        dp[0]=jobs[0][2];
        for(int i=1;i<n;i++)
        {
            int currStart=jobs[i][0];
            int currEnd=jobs[i][1];
            int currProfit=jobs[i][2];
            auto it=upper_bound(end.begin(), end.end(),currStart);
            int idx=(it-end.begin())-1;
            
            //pick
            if(idx>=0)
            {
                dp[i]=max(dp[i],currProfit+dp[idx]);
            }
            else{
                dp[i]=max(dp[i],currProfit+0);
            }
            //not pick
            dp[i]=max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
