#define ll long long int
const int N=100005;
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
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m=edges.size();
        if(m<n-1)
        {
            return -1;
        }
        dsu d;
        for(int i=0;i<n;i++)
        {
            d.make(i);
        }
        for(auto it:edges)
        {
            d.Union(it[0],it[1]);
        }
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(d.find(i)==i)
            {
                comp++;
            }
        }
        return comp-1;
    }
};