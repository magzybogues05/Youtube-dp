class Solution {
  public:
    
    void solve(int src,vector<int>&dist,vector<pair<int,int>>adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            for(auto i:adj[it.second])
            {
                if((it.first+i.second)<dist[i.first])
                {
                    dist[i.first]=it.first+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
    }
  
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,int>>adj[V];
        vector<pair<pair<int,int>,int>>curved;
        for(auto it:edges)
        {
            curved.push_back({{it[0],it[1]},it[3]});
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist1(V,INT_MAX);
        vector<int>dist2(V,INT_MAX);
        
        solve(a,dist1,adj);
        solve(b,dist2,adj);
        int ans=dist1[b];
        for(auto it:curved)
        {
            int a=it.first.first;
            int b=it.first.second;
            int wt=it.second;
            int costa1=dist1[a];
            int costb1=dist1[b];
            int costa2=dist2[a];
            int costb2=dist2[b];
            if(costa1!=INT_MAX && costb2!=INT_MAX)
            {
                ans=min(ans,costa1+costb2+wt);
            }
            if(costa2!=INT_MAX && costb1!=INT_MAX)
            {
                ans=min(ans,costa2+costb1+wt);
            }
        }
        
        if(ans==INT_MAX)
        {
            return -1;
        }
        
        return ans;
    }
};