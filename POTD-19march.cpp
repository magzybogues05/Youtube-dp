#define ll long long int
const ll N=100005;
class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    ll ans=0;
    
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
            ll aa=size[a];
            ll bb=size[b];
            ans-=(aa*(aa-1))/2;
            ans-=(bb*(bb-1))/2;
            ans+=((aa+bb)*(aa+bb-1))/2;
            size[a]+=size[b];
        }
    }
 
};

class Solution{
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    
	    vector<pair<int,int>>arr;
	    for(int i=0;i<queries.size();i++)
	    {
	        arr.push_back({queries[i],i});
	    }
	    sort(arr.begin(),arr.end());
	    sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
	       return a[2]<b[2]; 
	    });
	    dsu d;
	    for(int i=0;i<=n;i++)
	    {
	        d.make(i);
	    }
	    vector<int>ans(queries.size(),0);
	    int j=0;
	    for(int i=0;i<queries.size();i++)
	    {
	        for(;j<edges.size();j++)
	        {
	            if(edges[j][2]>arr[i].first)
	            {
	                break;
	            }
	            d.Union(edges[j][0],edges[j][1]);
	        }
	        ans[arr[i].second]=d.ans;
	    }
	    return ans;
	    // code here
	}
};