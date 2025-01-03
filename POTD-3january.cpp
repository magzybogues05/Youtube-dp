class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<int,int>mp;
        int xorr=0;
        long ans=0;
        mp[0]=1;
        for(auto it:arr)
        {
            xorr^=it;
            if(mp.find(xorr^k)!=mp.end())
            {
                ans+=mp[(xorr^k)];
            }
            mp[xorr]++;
        }
        return ans;
    }
};