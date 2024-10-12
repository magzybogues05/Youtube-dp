class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        
        int ans=-1;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,arr[i]+arr[i+1]);
        }
        return ans;
    }
};