#define mod 1000000007
class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        int n=arr.size();
        vector<long long> freq(n + 1, 0);
        vector<long long> power2(n + 1, 1);
        
        for (int x : arr) 
        {
            freq[x]++;
        }
        
        for (int i = 1; i <= n; i++) 
        {
            power2[i] = (power2[i - 1] * 2) % mod;
        }
        
        long long curProd = 1;
        long long cum = 0;
        long long ans = 0;
        
        for (int k = 0; k <= n; k++) 
        {
            cum += freq[k];
            
            if (k >= l && k <= r) 
            {
                long long ways = curProd * power2[n - cum] % mod;
                ans = (ans + ways) % mod;
            }
            
            curProd = curProd * (power2[freq[k]] - 1 + mod) % mod;
        }
        
        return ans;
    }
};