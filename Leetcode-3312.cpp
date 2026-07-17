class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
        {
            freq[x]++;
        }

        vector<long long> cnt(mx + 1, 0);

        for (int i = 1; i <= mx; i++) 
        {
            for (int j = i; j <= mx; j += i)
            {
                cnt[i] += freq[j];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int i = mx; i >= 1; i--) 
        {
            exact[i] = cnt[i] * (cnt[i] - 1) / 2;
            for (int j = i + i; j <= mx; j += i)
            {
                exact[i] -= exact[j];
            }
        }

        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
        {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;
        for (long long q : queries) 
        {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};