class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int i=0;
        int j=1;
        int n=arr.size();
        int ans=0;
        while(j<n)
        {
            if(arr[j]>arr[j-1])
            {
                if(j>i)
                {
                    ans+=(j-i);
                }
            }
            else{
                i=j;
            }
            j++;
        }
        return ans;
    }
};
