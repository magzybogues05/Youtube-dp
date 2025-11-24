class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int times=(i+1)*(n-i);
            if(times%2!=0)
            {
                ans^=arr[i];
            }
        }
        return ans;
    }
};