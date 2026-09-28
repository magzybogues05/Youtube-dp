class Solution {
  public:
  
    vector<int> tree;

    int build(int node, int l, int r, vector<int>& arr) {
        if (l == r)
        {
            return tree[node] = arr[l];
        }

        int mid = (l + r) / 2;

        int left = build(2 * node, l, mid, arr);
        int right = build(2 * node + 1, mid + 1, r, arr);

        return tree[node] = gcd(left, right);
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) 
        {
            tree[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
        {
            update(2 * node, l, mid, index, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, index, value);
        }

        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        // Completely outside
        if (r < ql || l > qr)
        {
            return 0;
        }

        // Completely inside
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }

        int mid = (l + r) / 2;

        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);

        return gcd(left, right);
    }
  
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, arr);

        vector<int> ans;

        for (auto& q : queries) 
        {
            if (q[0] == 0) 
            {
                int l = q[1];
                int r = q[2];

                ans.push_back(query(1, 0, n - 1, l, r));
            }
            else {
                
                int index = q[1];
                int value = q[2];

                update(1, 0, n - 1, index, value);
            }
        }

        return ans;
    }
};