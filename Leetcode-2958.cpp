class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        map<int,int>mp;
        int n=nums.size();
        int j=0;
        int i=0;
        int ans=0;
        while(i<n)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>k)
            {
                while(j<=i && mp[nums[i]]>k)
                {
                    mp[nums[j]]--;
                    j++;
                }
            }
            ans=max(ans,(i-j+1));
            i++;
        }
        return ans;
    }
};