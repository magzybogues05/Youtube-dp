class Solution {
  public:
    const int MAXH = 1001;
    auto update(int idx, int val, vector<int> &bit)
    {
        for(; idx <= MAXH; idx += idx & -idx)
        {
            bit[idx] = max(bit[idx], val);
        }
    }
    auto query(int idx, vector<int> &bit)
    {
        int res = 0;
        for(; idx > 0; idx -= idx & -idx)
        {
            res = max(res, bit[idx]);
        }
        return res;
    }
  
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        // code here
        int n = r.size();
        vector<pair<int,int>> discs(n);
        for(int i = 0; i < n; i++)
        {
            discs[i] = {r[i], h[i]};
        }
        sort(discs.begin(), discs.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first != b.first) 
            {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        
        vector<int> bit(MAXH + 2, 0);
        
        int ans = 0;
        for(auto d : discs) 
        {
            int height = d.second;
            int best = query(height - 1, bit);
            int curr = best + height;
            ans = max(ans, curr);
            update(height, curr, bit);
        }
        return ans;
    }
};