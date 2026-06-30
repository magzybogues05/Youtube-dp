class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st;
        int n=a.size();
        int m=b.size();

        for (int i = 0; i < m; i++)
        {
            st.insert(b[i]);
        }

        vector<int> arr;

        for (int i = 0; i < n; i++) 
        {
            if (st.count(a[i]))
            {
                arr.push_back(a[i]);
            }
        }

        vector<int> lis;

        for (int x : arr) 
        {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
            {
                lis.push_back(x);
            }
            else
            {
                *it = x;
            }
        }

        int len = lis.size();

        return (n - len) + (m - len);
    }
};