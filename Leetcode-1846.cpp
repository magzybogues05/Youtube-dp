class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int>count(n+1,0);
        for (auto it: arr)
        {
            count[min(it, n)]++;
        }

        int ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = min(ans + count[i], i);
        }
        return ans;
    }
};