#define ll long long int
class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int mid=n/2;
        vector<int> left(arr.begin(),arr.begin()+mid);
        vector<int> right(arr.begin()+mid,arr.end());
        map<ll,ll>mp;
        int m=right.size();
        for(int mask=0;mask<(1LL<<m);mask++)
        {
            ll sum=0;
            for(int i=0;i<m;i++)
            {
                if(mask&(1<<i))
                {
                    sum+=right[i];
                }
            }
            mp[sum]++;
        }
        int ans=0;
        m=left.size();
        for(int mask=0;mask<(1LL<<m);mask++)
        {
            ll sum=0;
            for(int i=0;i<m;i++)
            {
                if(mask&(1LL<<i))
                {
                    sum+=left[i];
                }
            }
            ans+=mp[k-sum];
        }
        return ans;
    }
};