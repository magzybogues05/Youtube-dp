class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < arr.size(); i++) 
        {
            mp[arr[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            
            if (!mp.count(x))
            {
                ans.push_back(0);
                continue;
            }
            
            int left = lower_bound(mp[x].begin(),mp[x].end(),l) - mp[x].begin();
            int right = upper_bound(mp[x].begin(),mp[x].end(),r) - mp[x].begin();
            
            ans.push_back(right - left);
        }
        
        return ans;
    }
};