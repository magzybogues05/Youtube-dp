class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        map<int,int>mp;
        int n=arr.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                ans=max(ans,i-mp[arr[i]]);
            }
            else{
                mp[arr[i]]=i;
            }
        }
        return ans;
    }
};