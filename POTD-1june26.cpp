#define ll long long int
#define mod 1000000007
class Solution {
  public:
    
    ll modpow(ll a,ll b,ll mmod)
    {
        // ll currmod=998244353;
        ll ans=1;
        while(b>0)
        {
            if(b%2==1)
            {
                ans=(ans%mmod*a%mmod)%mmod;
            }
            b=b/2;
            a=((a%mmod)*(a%mmod))%mmod;
        }
        return ans;
    }
    
    int findMaxProduct(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1)
        {
            return arr[0];
        }
        bool nonzero=false;
        bool pos=false;
        ll ans=1;
        int largestNegative=INT_MIN;
        int negative=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans=(ans%mod * arr[i]%mod)%mod;
                nonzero=true;
                pos=true;
            }
            else if(arr[i]<0)
            {
                ans=(ans%mod * arr[i]%mod)%mod;
                largestNegative=max(largestNegative,arr[i]);
                nonzero=true;
                negative++;
            }
        }
        if(ans<0)
        {
            ans=(ans%mod * modpow(largestNegative,mod-2,mod))%mod;
        }
        if(nonzero==false || (pos==false && negative<=1))
        {
            return 0;
        }
        return ans;
        
    }
};