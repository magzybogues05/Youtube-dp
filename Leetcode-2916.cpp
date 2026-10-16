#define MOD 1000000007
class Solution {
public:

    struct Node {
        long long sum;
        long long sqSum;
        long long lazy;
    };

    vector<Node> seg;

    void apply(int idx, int l, int r, long long val) 
    {
        long long len = r - l + 1;

        long long oldSum = seg[idx].sum;
        seg[idx].sqSum = (seg[idx].sqSum + 2 * val % MOD * oldSum % MOD + len % MOD * val % MOD * val % MOD) % MOD;

        seg[idx].sum = (oldSum + len * val) % MOD;
        seg[idx].lazy = (seg[idx].lazy + val) % MOD;
    }

    void push(int idx, int l, int r) 
    {
        if (seg[idx].lazy == 0 || l == r)
        {
            return;
        }

        int mid = (l + r) / 2;
        long long val = seg[idx].lazy;

        apply(idx * 2, l, mid, val);
        apply(idx * 2 + 1, mid + 1, r, val);

        seg[idx].lazy = 0;
    }

    void update(int idx, int l, int r, int ql, int qr, long long val) 
    {
        if (ql > r || qr < l)
        {
            return;
        }

        if (ql <= l && r <= qr) 
        {
            apply(idx, l, r, val);
            return;
        }

        push(idx, l, r);

        int mid = (l + r) / 2;

        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid + 1, r, ql, qr, val);

        seg[idx].sum = (seg[idx * 2].sum + seg[idx * 2 + 1].sum) % MOD;

        seg[idx].sqSum = (seg[idx * 2].sqSum + seg[idx * 2 + 1].sqSum) % MOD;
    }

    int sumCounts(vector<int>& nums) 
    {
        int n = nums.size();

        seg.assign(4*n + 10, {0, 0, 0});

        unordered_map<int, int> last;
        long long ans = 0;

        for (int r = 0; r < n; r++) 
        {
            int p = -1;

            if (last.count(nums[r]))
            {
                p = last[nums[r]];
            }

            update(1, 0, n - 1, p + 1, r, 1);

            ans = (ans + seg[1].sqSum) % MOD;

            last[nums[r]] = r;
        }

        return ans;
    }
};