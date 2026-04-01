class Solution {
  public:
    int countStrings(int n) {
        // code here
        int pzero=1;
        int pone=1;
        for(int i=2;i<=n;i++)
        {
            int zero=pzero+pone;
            int one=pzero;
            pzero=zero;
            pone=one;
        }
        return pzero+pone;
    }
};