class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(auto it:arr)
        {
            sum+=it;
            ans+=mp[sum-tar];
            mp[sum]++;
        }
        return ans;
        
    }
};