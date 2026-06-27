#define mod 1000000007
class Solution {
  public:
    int countWays(int n, int m) {
        // code here.
        deque<int>dp;
        for(int i=1;i<=n;i++)
        {
            if(i<m)
            {
                dp.push_back(1);
            }
            else if(i==m)
            {
                dp.push_back(2);
            }
            else
            {
                int ways=(dp.back()%mod+dp.front()%mod)%mod;
                dp.pop_front();
                dp.push_back(ways);
            }
        }
        return dp.back();
    }
};