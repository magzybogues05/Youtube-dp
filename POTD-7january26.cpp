class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<k-1;i++)
        {
            mp[arr[i]]++;
        }
        for(int i=k-1;i<n;i++)
        {
            mp[arr[i]]++;
            ans.push_back(mp.size());
            mp[arr[i-k+1]]--;
            if(mp[arr[i-k+1]]==0)
            {
                mp.erase(arr[i-k+1]);
            }
        }
        return ans;
    }
};