#define ll long long int
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        
        int n = arr.size();
        m = min(m, n);

        ll window = 0;
        ll ans = 0;

        for (int i = 0; i < m; i++)
        {
            window += arr[i];
        }

        ans = window;

        for (int i = m; i < n + m - 1; i++) 
        {
            window += arr[i % n];
            window -= arr[(i - m) % n];

            ans = max(ans, window);
        }

        return ans;
    }
};