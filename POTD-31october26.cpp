class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int n = arr.size();

        totalTime = min(totalTime,n);
        int sum = 0;

        for (int i = 0; i < totalTime; i++) 
        {
            sum += arr[i];
        }

        int ans = sum;

        for (int i = totalTime; i < n; i++) 
        {
            sum += arr[i];
            sum -= arr[i - totalTime];
            
            ans = max(ans, sum);
        }

        return ans;
    }
};