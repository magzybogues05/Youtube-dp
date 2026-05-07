class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefmx(n,0);
        vector<int> suffmn(n,0);

        for (int i = 0; i < n; i++) 
        {
            prefmx[i] = nums[i];
            if(i)
            {
                prefmx[i] = max(prefmx[i - 1], nums[i]);
            }
        }

        suffmn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) 
        {
            suffmn[i] = min(suffmn[i + 1], nums[i]);
        }

        vector<int>ans(n,0);
        ans[n - 1] = prefmx[n - 1];

        for (int i = n - 2; i >= 0; i--) 
        {
            if (prefmx[i] > suffmn[i + 1]) 
            {
                ans[i] = ans[i + 1];
            }
            else 
            {
                ans[i] = prefmx[i];
            }
        }

        return ans;
    }
};