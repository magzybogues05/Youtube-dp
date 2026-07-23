class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return n;
        }
        int bits = 0;
        while ((1 << bits) <= n) 
        {
            bits++;
        }
        return (1 << bits);
    }
};