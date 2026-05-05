#define ll long long int
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        ll ans = 0;
        
        for (int bit = 0; bit < 32; bit++) {
            ll one = 0;
            ll zero = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    one++;
                }
                else{
                    zero++;
                }
            }
            ans += one*zero*(1LL << bit);
        }
        
        return ans;
    }
};