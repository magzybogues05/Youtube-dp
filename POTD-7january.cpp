class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int i=0;
        int j=arr.size()-1;
        int ans=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum==target)
            {
                int c1=0;
                int c2=0;
                int ii=i;
                int jj=j;
                while(ii<j && arr[ii]==arr[i])
                {
                    c1++;
                    ii++;
                }
                while(jj>i && arr[jj]==arr[j])
                {
                    c2++;
                    jj--;
                }
                if(arr[i]==arr[j])
                {
                    ans+=((c1+1)*c1)/2;
                    break;
                }
                else{
                    ans+=(c1*c2);
                }
                i=ii;
                j=jj;
            }
            else if(sum<target)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};