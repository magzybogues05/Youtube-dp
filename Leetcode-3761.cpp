class Solution {
public:

    int reverse(int num)
    {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int it=nums[i];
            if(mp.find(it)!=mp.end())
            {
                ans=min(ans,(i-mp[it]));
            }
            int rev=reverse(it);
            mp[rev]=i;
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};