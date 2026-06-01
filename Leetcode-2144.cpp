class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0;
        int n=cost.size();
        for(int i=n-1;i>0;i-=3)
        {
            ans+=(cost[i]+cost[i-1]);
        }
        if(n%3==1)
        {
            ans+=cost[0];
        }
        return ans;
    }
};