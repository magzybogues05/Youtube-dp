#define ll long long int
#define mod 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<ll>dp(n+1,1);
        map<char,int>mp;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp[i-1]%mod*2%mod)%mod;
            if(mp.find(s[i-1])!=mp.end())
            {
                dp[i]=(dp[i]%mod-dp[mp[s[i-1]]-1]%mod+mod)%mod;
            }
            mp[s[i-1]]=i;
        }
        return (dp[n]%mod-1%mod+mod)%mod;
    }
};