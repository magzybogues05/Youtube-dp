#define ll long long int

class Solution {
  public:
    
    ll lcm(ll a, ll b) 
    {
        return (a*b)/__gcd(a, b);
    }
    
    void build(int node, int start, int end, vector<ll> &segTree, vector<int> &arr) 
    {
        if (start == end) {
            segTree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        
        build(2 * node, start, mid, segTree, arr);
        build(2 * node + 1, mid + 1, end, segTree, arr);
        
        segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
    }
    
    void update(int node, int start, int end, int idx, int val, vector<ll> &segTree) {
        if (start == end) 
        {
            segTree[node] = val;
            return;
        }
        
        int mid = (start + end) / 2;
        
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, val, segTree);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val, segTree);
        }
        
        segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
    }
  
    long long query(int node, int start, int end, int l, int r, vector<long long> &segTree) {
        if (r<start || end<l)
        {
            return 1;
        }
        
        if (l<=start && end<=r)
        {
            return segTree[node];
        }
        
        int mid = (start + end) / 2;
        
        ll left = query(2 * node, start, mid, l, r, segTree);
        ll right = query(2 * node + 1, mid + 1, end, l, r, segTree);
        
        return lcm(left, right);
    }
  
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<ll> segTree(4*n);
        
        build(1, 0, n - 1, segTree, arr);
        vector<ll> ans;
        for (auto &q : queries) 
        {
            if (q[0] == 1) 
            {
                int idx = q[1];
                int val = q[2];
                arr[idx] = val;
                update(1, 0, n - 1, idx, val, segTree);
            }
            else 
            {
                int l = q[1];
                int r = q[2];
                ans.push_back(query(1, 0, n - 1, l, r, segTree));
            }
        }
        return ans;
    }
};