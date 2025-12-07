#define ll long long int
#define mod 1000000007
class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        vector<ll>dp(n+1);
        vector<ll>prev(26, -1);
        dp[0]= 1;
        
        for(int i=1;i<=n;i++){
            int curr=(str[i-1]-'a');
            dp[i]=(2LL*dp[i-1])%mod;
            
            if(prev[curr]!=-1){
                dp[i]=(dp[i]%mod - dp[prev[curr]]%mod + mod)%mod;
            }
            prev[curr] = i-1;
        }
        return dp[n];
    }
};