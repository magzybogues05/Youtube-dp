class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
         if (n < 2) 
         {
             return n;
         }

        int a = 1;
        int b = 1;
    
        for (int i = 2; i <= n; i++) 
        {
            int c = b + (i - 1) * a;
            a = b;
            b = c;
        }
    
        return b;
    }
};