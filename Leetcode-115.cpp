#define ll long long int
class Solution {
public:
    int dp[1001][1001];
    ll solve(int i,int j,string &s,string &t)
    {
        if(j==t.size())
        {
            return 1;
        }
        if(i>=s.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        ll curr=0;
        if(s[i]==t[j])
        {
            curr+=solve(i+1,j+1,s,t);
        }
        curr+=solve(i+1,j,s,t);
        return dp[i][j]=curr;
    }
    
    int numDistinct(string s, string t) {
         
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,t);
    }
};