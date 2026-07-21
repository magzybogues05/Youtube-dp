class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.size();

        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) 
        {
            int temp = i;
            int curr = s[i] - 'a';
            if (curr < 25 && best[curr + 1] != -1)
            {
                temp = best[curr + 1];
            }

            best[curr] = max(best[curr], temp);

            if (curr == 0)
            {
                ans = max(ans, temp - i);
            }
        }

        return ans;
    }
};