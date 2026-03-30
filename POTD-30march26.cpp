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
    int minCost(vector<vector<int>>& houses) {
        // code here
        vector<pair<int,pair<int,int>>>arr;
        int n=houses.size();
        dsu d;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val=abs(houses[i][0]-houses[j][0])+abs(houses[i][1]-houses[j][1]);
                arr.push_back({val,{i,j}});
            }
            d.make(i);
        }
        sort(arr.begin(),arr.end());
        
        int ans=0;
        for(auto it:arr)
        {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(d.find(u)!=d.find(v))
            {
                d.Union(u,v);
                ans+=wt;
            }
        }
        return ans;
    }
};