class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mx=nums[n-1];
        int mx2=nums[n-2];
        int mx3=nums[n-3];
        int mn=nums[0];
        int mn2=nums[1];
        int mn3=nums[2];
        int ans=mx-mn;
        ans=min(ans,(mx2-mn2));
        ans=min(ans,(mx-mn3));
        ans=min(ans,(mx3-mn));
        return ans;
    }
};