#define ll long long int
#define mod 1000000007
class Solution {
public:

    ll modpow(ll a,ll b,ll mmod)
    {
        // ll currmod=998244353;
        ll ans=1;
        while(b>0)
        {
            if(b%2==1)
            {
                ans=(ans%mmod*a%mmod)%mmod;
            }
            b=b/2;
            a=((a%mmod)*(a%mmod))%mmod;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>adj[100005];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        int level=0;
        q.push({1,-1});
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto it=q.front();
                q.pop();
                for(auto itt:adj[it.first])
                {
                    if(itt!=it.second)
                    {
                        q.push({itt,it.first});
                    }
                }
            }
            level++;
        }
        level--;
        ll ans=modpow(2,level-1,mod);
        return ans;
    }
};