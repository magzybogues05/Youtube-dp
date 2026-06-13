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
    
    int computeValue(int n) {
        // code here
        ll ans=1;
        ll temp=1;
        for(int i=0;i<n;i++)
        {
            ans=(ans%mod*(2*n-i)%mod)%mod;
            temp=(temp%mod*(i+1))%mod;
        }
        ans=(ans%mod*modpow(temp,mod-2,mod)%mod)%mod;
        return ans;
    }
};