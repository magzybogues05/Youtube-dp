class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans = 0;

        while (n > 0 && m > 0) 
        {
            ans += n / m;
            n %= m;
            swap(n, m);
        }

        return ans;
    }
};