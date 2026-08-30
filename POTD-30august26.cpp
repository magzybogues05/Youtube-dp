#define ll long long int
class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();

        vector<ll> prefix(n);

        ll sum = 0;

        for (int i = 0; i < n; i++) 
        {
            sum += r[i] - l[i] + 1;
            prefix[i] = sum;
        }

        vector<int> ans;

        for (int k : rank) {

            int i = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();

            ll previous = (i == 0 ? 0 : prefix[i - 1]);

            int mark = l[i] + (k - previous - 1);

            ans.push_back(mark);
        }

        return ans;
    }
};