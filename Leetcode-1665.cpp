#define ll long long int
class Solution {
public:

    bool check(ll mid,vector<vector<int>>&tasks)
    {
        for(auto it:tasks)
        {
            if(mid<it[1])
            {
                return false;
            }
            mid-=it[0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(),tasks.end(),[&](vector<int>&a,vector<int>&b){
            return (a[1]-a[0] > b[1]-b[0]);
        });
        int ans=INT_MAX;
        ll l=0;
        ll h=INT_MAX;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            if(check(mid,tasks))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};