class Solution {
  public:
    int minOperation(int n) {
        // code here
        int ans = 0;

        while(n) 
        {
            if (n % 2 == 0)
            {
                n /= 2;
            } 
            else
            {
                n--;
            }
            
            ans++;
        }

        return ans;
    }
};