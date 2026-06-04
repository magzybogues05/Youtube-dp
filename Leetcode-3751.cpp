class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<int>pref(100001,0);
        vector<int>dp(100001,0);
        for (int i = 100; i < 100001; i++) 
        {
            int r = i % 10;
            int m = (i / 10) % 10;
            int l = (i / 100) % 10;

            bool isWave = (m > max(l, r)) | (m < min(l, r));
            dp[i] = dp[i / 10] + isWave;
            pref[i] = pref[i - 1] + dp[i];
        }
        return pref[num2] - pref[num1 - 1];
    }
};