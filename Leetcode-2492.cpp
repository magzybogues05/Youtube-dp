#define ll long long int
const int N= 1e6+10;

class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    ll mn[2*N];
    
    void make(ll v)
    {
        par[v]=v;
        size[v]=1;
        mn[v]=LLONG_MAX;
    }
    ll find(ll v)
    {
        if(v==par[v])
        {
            return v;
        }
        return par[v]=find(par[v]);
    }
    void Union(ll a,ll b,ll d)
    {
        a=find(a);
        b=find(b);
        mn[a]=min(d,min(mn[a],mn[b]));
        mn[b]=min(d,min(mn[a],mn[b]));
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                swap(a,b);
            }

            par[b]=a;
            size[a]+=size[b];
        }
    }

};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        dsu d;
        for(int i=1;i<=n;i++)
        {
            d.make(i);
        }
        for(auto &it:roads)
        {
            d.Union(it[0],it[1],it[2]);
        }
        ll p=d.find(1);
        return d.mn[p];
        
    }
};