class Solution {
  public:
  
    int solve(vector<int>&arr, int k){
        int n=arr.size();
        int i=0;
        int j=0;
        int odd=0;
        int ans=0;
        while(i<n)
        {
            if(arr[i]%2==1)
            {
                odd++;
            }
            
            while(odd>k)
            {
                if(arr[j]%2==1)
                {
                    odd--;
                }
                j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return solve(arr,k)-solve(arr,k-1);
    }
};