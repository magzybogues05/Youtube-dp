class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        const int BITS = 31;
        vector<int> basis(BITS + 1, 0);
    
        for (int x : arr) 
        {
            int num = x;
    
            for (int bit = BITS; bit >= 0; bit--) 
            {
    
                if ((num & (1 << bit)) == 0)
                {
                    continue;
                }
    
                if (basis[bit] == 0) 
                {
                    basis[bit] = num;
                    break;
                }
                num ^= basis[bit];
            }
        }
        
        int ans = 0;
    
        for (int bit = BITS; bit >= 0; bit--) 
        {
            if ((ans ^ basis[bit]) > ans)
            {
                ans ^= basis[bit];
            }
        }
    
        return ans;
    }
};