class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        vector<int>st;
        for(int i=0;i<n/2;i++)
        {
            st.push_back(arr[i]);
        }
        int ans=0;
        sort(st.begin(),st.end());
        for(int i=n/2;i<n;i++)
        {
            auto it=lower_bound(st.begin(),st.end(),(arr[i]*5LL));
            ans+=(st.end()-it);
            // cout<<ans<<endl;
        }
        return ans;
    }
};