class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,0);

        for (int i = 0; i < n; i++) {
            ans[i] = arr[i];
            if(i)
            {
                ans[i]+=ans[i-1];
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int k = i / 2;
            int prefI = ans[i];
            int prefK = ans[k];
            int left = (arr[k] * (k + 1)) - prefK;
            long long right = (prefI - prefK) - (arr[k] * (i - k));
            ans[i] = left + right;
        }
        return ans;
    }
};