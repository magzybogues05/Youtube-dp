#define ll long long int
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();

        ll prevNoDelete = arr[0];
        ll prevOneDelete = INT_MIN;
        ll ans = arr[0];

        for (int i = 1; i < n; i++) {
            
            ll currNoDelete=max(arr[i]*1LL, prevNoDelete + arr[i]);
            ll currOneDelete = max(prevNoDelete, prevOneDelete + arr[i]);

            ans = max({ans, currNoDelete, currOneDelete});
            prevNoDelete = currNoDelete;
            prevOneDelete = currOneDelete;
        }

        return ans;
    }
};