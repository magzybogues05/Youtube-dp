#define ll long long int
class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        vector<ll> maxEnd(n,0);

        maxEnd[0] = arr[0];
        for(int i = 1; i < n; i++) 
        {
            maxEnd[i] = max(1LL*arr[i], maxEnd[i - 1] + arr[i]);
        }

        ll windowSum = 0;
        for (int i = 0; i < k; i++)
        {
            windowSum += arr[i];
        }

        ll ans = windowSum;

        for (int i = k; i < n; i++) 
        {
            windowSum += arr[i];
            windowSum -= arr[i - k];

            ans = max(ans, windowSum);
            ans = max(ans, windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};