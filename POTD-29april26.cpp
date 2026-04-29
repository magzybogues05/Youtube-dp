class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ones=0;
        for(auto it:arr){
            if(it==1)
            {
                ones++;
            }
        }
        if(ones==0)
        {
            return -1;
        }
        int one=0;
        int zero=0;
        for(int i=0;i<ones-1;i++)
        {
            if(arr[i]==0)
            {
                zero++;
            }
            else{
                one++;
            }
        }
        int ans=INT_MAX;
        int j=ones-1;
        while(j<n){
            if(arr[j]==0)
            {
                zero++;
            }
            else
            {
                one++;
            }
            ans=min(ans,zero);
            j++;
            if(arr[j-ones]==0)
            {
                zero--;
            }
            else{
                one--;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};