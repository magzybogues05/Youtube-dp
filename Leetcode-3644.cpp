class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        bool flag=false;
        int ans=(1LL<<30)-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                flag=true;
                ans&=nums[i];
            }
        }
        if(flag)
        {
            return ans;
        }
        return 0;
    }
};