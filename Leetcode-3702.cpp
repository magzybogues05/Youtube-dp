class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        bool hasNonZero = false;

        for(int it : nums) 
        {
            xorr ^= it;
            if(it != 0)
            {
                hasNonZero = true;
            }
        }

        if (xorr != 0)
        {
            return n;
        }

        if (hasNonZero)
        {
            return n - 1;
        }

        return 0;
    }
};