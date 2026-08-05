class Solution {
  public:
  
    int solve(vector<int>&arr,int k)
    {
        
        int i = 0;
        int j = 0;
        int n = arr.size();
        int count = 0;
        int sum = 0;
        while(j<n)
        {
          sum = sum + arr[j];
          while(sum > k)
          {
            count = count + (n-j);
            sum = sum - arr[i];
            i++;
          }
          j++;
        }
        return count;
    }
  
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int x = solve(arr,r);
        int y = solve(arr,l-1);
        return (y - x);
    }
};