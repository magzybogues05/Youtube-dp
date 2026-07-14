#define ll long long int
#define mod 1000000007
class Solution {
    ll dp[201][201][201];
public:

    ll solve(int i, vector<int> &nums, int gcd1, int gcd2)
    {

        if(i == nums.size())
        {
            
            return (gcd1 && gcd2 && gcd1==gcd2);
        }
        
        if(dp[i][gcd1][gcd2] != -1) 
        {
            return dp[i][gcd1][gcd2];
        }
        
        ll skip = solve(i + 1, nums, gcd1, gcd2);
        ll take1 = solve(i + 1, nums, __gcd(gcd1, nums[i]), gcd2);
        ll take2 = solve(i + 1, nums, gcd1, __gcd(gcd2, nums[i]));
        ll ans=(skip+take1+take2)%mod;
        return dp[i][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, 0);
    }
};