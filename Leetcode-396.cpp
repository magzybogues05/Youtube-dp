class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int F = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        int ans = F;

        for (int i = 1; i < n; i++) {
            F += sum - (n * nums[n - i]);
            ans = max(ans, F);
        }

        return ans;
    }
};