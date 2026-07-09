#define ll long long int
class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mp;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]%k;
            if(mp.find((k-arr[i])%k)!=mp.end())
            {
                ans+=mp[(k-arr[i])%k];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};