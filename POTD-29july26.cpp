class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        set<int>st;
        for(auto it:arr)
        {
            st.insert(it);
        }
        int ans=0;
        for(auto it:arr)
        {
            if(st.find(it-1)==st.end())
            {
                ans++;
            }
        }
        return ans;
    }
};