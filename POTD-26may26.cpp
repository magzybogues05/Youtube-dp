class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int zero=0;
        int n=arr.size();
        for(auto it:arr)
        {
            if(it==0)
            {
                zero++;
            }
        }
        int o=0;
        int z=0;
        int ans=n;
        for(int i=0;i<=n;i++)
        {
            int temp=o+(zero-z);
            ans=min(ans,temp);
            if(i<n)
            {
                if(arr[i]==0)
                {
                    z++;
                }
                else{
                    o++;
                }
            }
        }
        return ans;
    }
};
