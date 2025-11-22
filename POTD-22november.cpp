#define ll long long int
const int N=4005;
class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    ll zerosize[2*N];
    
    void make(ll v)
    {
        par[v]=v;
        size[v]=1;
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
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                swap(a,b);
            }
            par[b]=a;
            size[a]+=size[b];
            zerosize[a]+=zerosize[b];
        }
    }

};

class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        dsu d;
        int extra=0;
        for(int i=0;i<V;i++)
        {
            d.make(i);
        }
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int parU=d.find(u);
            int parV=d.find(v);
            if(parU==parV)
            {
                extra++;
            }
            else{
                d.Union(u,v);
            }
            
        }
        int component=0;
        for(int i=0;i<V;i++)
        {
            if(d.find(i)==i)
            {
                component++;
            }
        }
        if(component>extra+1)
        {
            return -1;
        }
        return (component-1);
        
    }
};
