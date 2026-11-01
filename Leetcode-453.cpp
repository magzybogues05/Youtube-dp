class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n=nums.size();
        
        int sum=0;
        int mn=INT_MAX;
        for(auto it:nums)
        {
            sum+=it;
            mn=min(mn,it);
        }
        return sum-n*mn;
    }
};