class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n==0)
        {
            return -1;
        }
        if((n&(n-1))==0)
        {
            return log2(n)+1;
        }
        return -1;
    }
};