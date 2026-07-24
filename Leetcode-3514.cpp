class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int>dbl(3001,0);
        for(auto it:nums)
        {
            for(auto itt:nums)
            {
                dbl[it^itt]=1;
            }
        }
        vector<int>tpl(3001,0);
        for(int i=0;i<dbl.size();i++)
        {
            if(dbl[i]==1)
            {
                for(auto it:nums)
                {
                    tpl[(i^it)]=1;
                }
            }
        }
        int ans=0;
        for(auto it:tpl)
        {
            if(it==1)
            {
             ans++;
            }
        }
        return ans;
    }
};