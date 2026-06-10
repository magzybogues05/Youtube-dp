class Solution {
  public:
        
    void solve(vector<int>&arr, int l, int r, int mn, int mx,int &ans) {
        if (l > r)
        {
            return;
        }

        int mid = (l + r) / 2;

        if (arr[mid] > mn && arr[mid] < mx) {
            ans++;
        }

        solve(arr, l, mid - 1, mn, min(mx, arr[mid]), ans);
        solve(arr, mid + 1, r, max(mn, arr[mid]), mx, ans);
    }
    
    int binarySearchable(vector<int>& arr) {
        // code here
        int ans=0;
        solve(arr,0,arr.size()-1,INT_MIN,INT_MAX,ans);
        return ans;
    }
};