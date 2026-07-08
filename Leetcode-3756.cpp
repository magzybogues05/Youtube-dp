#define mod 1000000007
#define ll long long int
class Solution {

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        ll pow[100001];
        pow[0] = 1;
        for (int i = 1; i < 100001; i++)
        {
            pow[i] = pow[i - 1] * 10 % mod;
        }

        vector<ll> pref(n + 1, 0);
        vector<ll> number(n + 1, 0);
        vector<int> len(n + 1, 0);

        for (int i = 0; i < n; i++) 
        {
            int d = s[i] - '0';
            pref[i + 1] = pref[i] + d;
            number[i + 1] = d ? (number[i] * 10 + d) % mod : number[i];
            len[i + 1] = len[i] + (d > 0);
        }

        vector<int> ans;

        for (auto it : queries) 
        {
            int l = it[0], r = it[1] + 1;

            ll sub = (number[l] * 1LL * pow[len[r] - len[l]]) % mod;
            ll num = (number[r] - sub + mod) % mod;

            ans.push_back(num * (pref[r] - pref[l]) % mod);
        }

        return ans;
    }
};