#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        ll ans=LLONG_MIN;
        ll n=nums.size();
        ll sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        if(x>sum)
        {
            return -1;
        }
        sum-=x;
        if(sum==0)
        {
            return nums.size();
        }
        ll curr=0;
        ll i=0;
        ll j=0;
        while(i<nums.size())
        {
            curr+=nums[i];
            if(curr==sum)
            {
                ans=max(ans,i-j+1);
            }
            else if(curr>sum)
            {
                while(j<i && curr>sum)
                {
                    curr-=nums[j];
                    j++;
                }
                if(curr==sum)
                {
                    ans=max(ans,i-j+1);
                }
            }
            i++;
        }
        if(ans==LLONG_MIN)
        {
            return -1;
        }
        return n-ans;
    }
};  