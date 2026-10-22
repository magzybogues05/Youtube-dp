class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int k = nums[0];
        bool increasing = true;
        int idx=-1;
        for (int i = 0; i < n; i++) 
        {
            if(nums[i]==0)
            {
                idx=i;
            }
            if (nums[i] != k) 
            {
                increasing = false;
                break;
            }
            k = (k + 1) % n;
        }

        k=nums[0];
        bool decreasing = true;
        for (int i = 0; i < n; i++) 
        {
            if(nums[i]==0)
            {
                idx=i;
            }
            
            if (nums[i] != k) 
            {
                decreasing = false;
                break;
            }

            k = (k - 1 + n) % n;
        }

        if (increasing) 
        {
            return min( idx , n - idx + 2 );
        }

        if (decreasing)
        {
            return min( n - idx , idx + 2 );
        }
        return -1;
    }
};