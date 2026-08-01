#define ll long long int
class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<long long> diff(n + 1, 0);

        int m = a.size();

        for (int i = 0; i < m; i++) 
        {
            diff[a[i]] += k[i];
            if (b[i] + 1 < n)
            {
                diff[b[i] + 1] -= k[i];
            }
        }

        ll curr = 0;
        ll ans = 0;

        for (int i = 0; i < n; i++) 
        {
            curr += diff[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};