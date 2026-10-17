class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int val=nums[i];
            while(val)
            {
                sum+=(val%10);
                val/=10;
            }
            arr.push_back({sum,i});
        }
        sort(arr.begin(),arr.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)
            {
                return nums[a.second]<nums[b.second];
            }
            return a.first<b.first;
        });
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            arr[i].first=nums[arr[i].second];
            mp[nums[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            int exp=arr[i].first;
            if(curr!=exp)
            {
                int idx=mp[exp];
                mp[curr]=idx;
                nums[idx]=curr;
                ans++;
            }
        }
        return ans;
    }
};