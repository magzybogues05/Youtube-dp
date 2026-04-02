class Solution {
  public:
    int countWays(int n, int k) {
        if (n == 1) return k;
    
        int same = k;
        int diff = k * (k - 1);
    
        for (int i = 3; i <= n; i++) {
            int newSame = diff;
            int newDiff = (same + diff) * (k - 1);
    
            same = newSame;
            diff = newDiff;
        }
    
        return same + diff;
    }
};