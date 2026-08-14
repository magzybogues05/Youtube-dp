#define ll long long int
class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<ll> nums;

        ll sum = s;
        nums.push_back(s);

        for (int a : arr) 
        {
            ll next = sum + a;

            if (next > x)
            {
                break;
            }

            nums.push_back(next);
            sum += next;
        }

        ll target = x;

        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            if (nums[i] <= target) 
            {
                target -= nums[i];
            }

            if (target == 0)
            {
                return true;
            }
        }

        return false;
    }
};