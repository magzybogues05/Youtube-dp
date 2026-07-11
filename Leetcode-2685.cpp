#define ll long long int
const int N= 1e6+10;

class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    ll ed[N+1];

    
    void make(ll v)
    {
        par[v]=v;
        size[v]=1;
        ed[v]=0;
    }
    ll find(ll v)
    {
        if(v==par[v])
        {
            return v;
        }
        return par[v]=find(par[v]);
    }
    void Union(ll a,ll b)
    {
        a=find(a);
        b=find(b);
        ed[a]++;
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                swap(a,b);
            }
            par[b]=a;
            ed[a]+=ed[b];
            size[a]+=size[b];
        }
    }

};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        dsu d;
        for(int i=0;i<n;i++)
        {
            d.make(i);
        }
        
        for(auto it:edges)
        {
            d.Union(it[0],it[1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(d.find(i)==i)
            {
                int node=d.size[i];
                int edge=d.ed[i];
                if(edge==(node*(node-1))/2)
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};