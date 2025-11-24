#define ll long long int
const int N=1000;
class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    
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
        }
    }

};

class Solution {
  public:
    int secondMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        
        dsu d;
        for(int i=0;i<V;i++)
        {
            d.make(i);
        }
        vector<int>used;
        int totalcost=0;
        for(int i=0;i<edges.size();i++)
        {
            auto it=edges[i];
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            if(d.find(u)!=d.find(v))
            {
                d.Union(u,v);
                totalcost+=cost;
                used.push_back(i);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<used.size();i++)
        {
        
            for(int k=0;k<V;k++)
            {
                d.make(k);
            }
            int jj=used[i];
            int newcost=0;
            for(int j=0;j<edges.size();j++)
            {
                if(jj!=j)
                {
                    if(d.find(edges[j][0])!=d.find(edges[j][1]))
                    {
                        d.Union(edges[j][0],edges[j][1]);
                        newcost+=edges[j][2];
                    }
                }
            }
            int comp=0;
            for(int k=0;k<V;k++)
            {
                if(d.find(k)==k)
                {
                    comp++;
                }
            }
            if(comp==1 && newcost>totalcost)
            {
                ans=min(ans,newcost);
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
        
    }
};