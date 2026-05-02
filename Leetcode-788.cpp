class Solution {
public:

    int dp[6][2][2][2];
    string s;

    bool isValid(int d) {
        return !(d == 3 || d == 4 || d == 7);
    }

    bool isChanging(int d) {
        return (d == 2 || d == 5 || d == 6 || d == 9);
    }

    int solve(int pos, int tight, int hasChanged, int started) {
        if (pos == s.size()) {
            return (started && hasChanged);
        }

        if (dp[pos][tight][hasChanged][started] != -1)
            return dp[pos][tight][hasChanged][started];

        int limit = tight ? (s[pos] - '0') : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == limit);

            if (!started && d == 0) {
                // still leading zero
                ans += solve(pos + 1, newTight, 0, 0);
            } else {
                if (!isValid(d)) continue;

                int newHasChanged = hasChanged || isChanging(d);
                ans += solve(pos + 1, newTight, newHasChanged, 1);
            }
        }

        return dp[pos][tight][hasChanged][started] = ans;
    }


    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, 0);
    }
};