#define ll long long int 
const int N=400005;

class dsu
{
public:
    ll par[2*N];
    ll size[2*N];
    ll parity[2*N];
    
    void make(ll v)
    {
        par[v] = v;
        size[v] = 1;
        parity[v] = 0;
    }
    
    ll find(ll v)
    {
        if(v == par[v])
        {
            return v;
        }
        ll orig_parent = par[v];
        par[v] = find(par[v]);
        parity[v] ^= parity[orig_parent];
        return par[v];
    }
    
    void Union(ll u, ll v, ll w)
    {
        ll ru = find(u);
        ll rv = find(v);
        
        if(size[ru] < size[rv])
        {
            swap(ru, rv);
            swap(u, v);
        }
        
        par[rv] = ru;
        
        parity[rv] = parity[u] ^ parity[v] ^ w;
        
        size[ru] += size[rv];
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
    
        dsu d;
        
        for(int i = 0; i < n; i++) {
            d.make(i);
        }
        
        int count = 0;
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            int ru = d.find(u);
            int rv = d.find(v);
            
            if(ru == rv)
            {
                if((d.parity[u] ^ d.parity[v]) == w) {
                    count++;
                }
            }
            else
            {
                d.Union(u, v, w);
                count++;
            }
        }
        
        return count;
    }
};