class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() 
        {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) 
        {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node &L, Node &R) 
    {
        if (L.len == 0) 
        {
            return R;
        }
        if (R.len == 0)
        {
           return L;
        }

        Node res;

        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.prefix = L.prefix;
        res.suffix = R.suffix;
        res.best = max(L.best, R.best);

        if (L.rightChar == R.leftChar) 
        {

            res.best = max(res.best, L.suffix + R.prefix);
            
            if (L.prefix == L.len)
            {
                res.prefix = L.len + R.prefix;
            }

            if (R.suffix == R.len)
            {
                res.suffix = R.len + L.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        int k = queryIndices.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) 
        {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};