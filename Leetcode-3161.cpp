#define ll long long int
class Solution {
public:

    ll solve(int i,vector<ll>&bit)
    {
        ll ans=0;
        for(;i>0;i-=(i&-i))
        {
            ans=max(bit[i],ans);
        }
        // cout<<endl;
        return ans;
    }

    void update(int i,ll x,vector<ll>&bit)
    {
        for(;i<bit.size();i+=(i&-i))
        {
            bit[i]=max(bit[i],x);
        }
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<ll>bit(50001,0);
        set<int> blocks{0};
        for (auto q : queries)
            if (q[0] == 1)
            {
                blocks.insert(q[1]);
            }
        for (auto it = next(begin(blocks)); it != end(blocks); it++)
        {
            int curr=*it;
            int pre=*prev(it);
            update(curr, curr - pre,bit);
        }
        for (int i = queries.size() - 1; i >= 0; i--) 
        {
            int x=queries[i][1];
            auto it=blocks.lower_bound(x);
            if(queries[i][0]==1)
            {
                if (next(it) != end(blocks))
                {
                    update(*next(it), *next(it) - *prev(it),bit);
                }
                blocks.erase(it);
            }
            else
            {
                int size=queries[i][2];
                int d= x- *prev(it);
                if(d>=size || solve(x,bit) >= size)
                {
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};