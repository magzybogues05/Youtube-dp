#define ll long long int
#define mod 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums, int k) 
    {
        vector<int>freq(31,0);
        ll ans=0;
        for (int num : nums)
        {
            for (int i = 0; i < 30; i++)
            {
                if (num & (1 << i))
                {
                    freq[i]++;
                }
            }
        }

        while(k--) 
        {
            ll val=0;
            for (int i = 0; i < 30; i++)
            {
                if (freq[i] > 0) 
                {
                    val |= (1LL << i);
                    freq[i]--;
                }
            }
            ll sq=(val%mod * val%mod)%mod;
            ans = (ans%mod + sq%mod) % mod;
        }

        return ans;
    }
};