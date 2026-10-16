class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<int> suffmin(n,0);
        suffmin[n - 1] = INT_MAX;
        int mn=arr[n-1];

        for (int i = n - 2; i >= 0; i--) 
        {
            suffmin[i] = mn;
            mn= min(arr[i], mn);
        }

        int ans = 0;
        int prefmax = INT_MIN;

        for (int i = 0; i < n; i++) 
        {
            if (prefmax < arr[i] && (arr[i] < suffmin[i]))
            {
                ans++;
            }
            prefmax = max(prefmax, arr[i]);
        }

        return ans;
    }
};