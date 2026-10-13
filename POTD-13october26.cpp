class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        
        vector<int>ans(n,0);
        for(auto it:updates)
        {
            ans[it-1]++;
        }
        for(int i=1;i<n;i++)
        {
            ans[i]+=ans[i-1];
        }
        return ans;
        
    }
};