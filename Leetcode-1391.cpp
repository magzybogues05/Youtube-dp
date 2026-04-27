#define ll long long int
const int N= 1e6+10;
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
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        dsu d;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<N;i++)
        {
            d.make(i);
        }
        d.Union(0,(2*(m+1)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int u=((2*i+1)*(m+1))+j;
                    int v=((2*i+1)*(m+1))+(j+1);
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
                else if(grid[i][j]==2)
                {
                    int u=((2*i)*(m+1))+j;
                    int v=((2*i+2)*(m+1))+(j);
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
                else if(grid[i][j]==3)
                {
                    int u=((2*i+1)*(m+1))+j;
                    int v=((2*i+2)*(m+1))+(j);
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
                else if(grid[i][j]==4)
                {
                    int u=((2*i+1)*(m+1))+(j+1);
                    int v=((2*i+2)*(m+1))+(j);
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
                else if(grid[i][j]==5)
                {
                   int u=((2*i)*(m+1))+j;
                    int v=((2*i+1)*(m+1))+j;
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
                else if(grid[i][j]==6){
                     int u=((2*i)*(m+1))+j;
                    int v=((2*i+1)*(m+1))+(j+1);
                    // cout<<u<<" "<<v<<endl;
                    d.Union(u,v);
                }
            }
        }
        
        int u1=0;
        int u2=m+1;
        int v1=(2*n*(m+1))+(m-1);
        int v2=(((2*n)-1)*(m+1))+m;
        int temp=(2*(n-1)*(m+1))+(m-1);
        d.Union(v1,temp);
        
        u1=d.find(u1);
        u2=d.find(u2);
        v1=d.find(v1);
        v2=d.find(v2);
        // cout<<u1<<endl;
        // cout<<u2<<endl;
        // cout<<v1<<endl; 
        // cout<<v2<<endl;
        if((u1==v1) || (u1==v2) || (u2==v1) || (u2==v2))
        {
            return true;
        }
        return false;
        
    }
};