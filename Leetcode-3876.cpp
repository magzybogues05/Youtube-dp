class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int smallestOdd = INT_MAX;
        for (int num : nums)
        {
            if (num % 2 == 1)
            {
                smallestOdd = min(smallestOdd, num);
            }
        }

        if (smallestOdd == INT_MAX) 
        {
            return true;
        }
        
        for (int num : nums)
        {
            if (num % 2 == 0 && num <= smallestOdd)
            {
                return false;
            }    
        }
        return true;
    }
};