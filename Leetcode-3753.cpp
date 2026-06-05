#define ll long long int
class Solution {
public:

    pair<ll,ll> dp[2][2][17][11][11];
    pair<ll,ll> solve(int idx, int flag, int zero, int prev2, int prev,string &str)
    {
        if(idx == str.size())
        {
            return {1,0};
        }
        if(dp[flag][zero][idx][prev2][prev]!=make_pair(-1LL, -1LL))
        {
            return dp[flag][zero][idx][prev2][prev];
        }
        int limit=9;
        pair<ll,ll>ans={0,0};
        if(flag==0)
        {
            limit=(str[idx]-'0');
        }
        for(int i=0;i<=limit;i++)
        {
            if(zero && i==0)
            {
                auto it=solve(idx+1,1,1,10,10,str);
                ans.first+=it.first;
                ans.second+=it.second;
            }
            else if(i==limit)
            {
                auto it=solve(idx+1,flag,0,prev,i,str);
                int curr=0;
                if(prev2!=10 && prev!=10)
                {
                    if(prev> max(i,prev2) || prev< min(i,prev2))
                    {
                        curr=1;
                    }
                }
                ans.first+=it.first;
                ans.second+=it.second + it.first*curr;
            }     
            else{
                auto it=solve(idx+1,1,0,prev,i,str);
                int curr=0;
                if(prev2!=10 && prev!=10)
                {
                    if(prev> max(i,prev2) || prev< min(i,prev2))
                    {
                        curr=1;
                    }
                }
                ans.first+=it.first;
                ans.second+=it.second + it.first*curr;
            }
        }
        return dp[flag][zero][idx][prev2][prev]=ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        string l=to_string(num1-1);
        string r=to_string(num2);
        memset(dp,-1,sizeof dp);
        auto ans=solve(0,0,1,10,10,r);
        memset(dp,-1,sizeof dp);
        auto temp=solve(0,0,1,10,10,l);
        return ans.second-temp.second;
    }
};