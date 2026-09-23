#define ll long long int
class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<ll> left(n,0);
        vector<ll> right(n,0);
        left[0] = min(arr[0], 1);

        for (int i = 1; i < n; i++) 
        {
            left[i] = min(arr[i]*1LL, left[i-1] + 1);
        }
        
        right[n - 1] = min(arr[n - 1], 1);

        for (int i = n - 2; i >= 0; i--) 
        {
            right[i] = min(arr[i]*1LL, right[i+1] + 1);
        }

        ll sum = 0;
        ll bestPyramid = 0;

        for (int i = 0; i < n; i++) 
        {
            sum += arr[i];
            ll peak = min(left[i], right[i]);
            bestPyramid = max(bestPyramid, peak * peak);
        }

        return sum - bestPyramid;
    }
};