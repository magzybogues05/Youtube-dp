class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
         int n = arr.size();
        queue<int> q;
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            
            if (!q.empty() && q.front() + k == i) {
                q.pop();
            }
    
            if ((arr[i] + q.size()) % 2 == 0) {
                if (i + k > n)
                {
                    return -1;
                }
                ans++;
                q.push(i);
            }
        }
    
        return ans;
    }
};