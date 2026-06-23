#define ll long long int
class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        ll low = 0;
        ll high = 10000;
        
        ll ans = 0;
        
        while (low <= high) 
        {
            long long mid = low + (high - low) / 2;
            
            ll sum = (mid * (mid + 1) * (2 * mid + 1)) / 6;
            
            if (sum <= p)
            {
                ans = mid;
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};