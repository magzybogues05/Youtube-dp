class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] == '1')
        {
            return false;
        }

        vector<int>pref(n+1,0);
        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += pref[i];

            if (i == 0 || (sum && (s[i] == '0'))) 
            {
                int l= min(i+minJump,n);
                int r= min(i+maxJump+1,n);
                pref[l]++;
                pref[r]--;
            }
        }

        return (sum > 0);
    }
};