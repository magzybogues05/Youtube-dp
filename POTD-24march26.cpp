class Solution {
  public:
  
    void solve(int i,int curr,vector<int>graph[],vector<int>&vis,bool &ans)
    {
        
        vis[i]=curr;
        for(int it:graph[i])
        {
            if(vis[it]!=-1)
            {
                if(vis[it]==curr)
                {
                    ans=false;
                }
            }
            else{
                solve(it,curr,graph,vis,ans);
            }
        }
        vis[i]=-2;
    }
  
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<int>adj[n];
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
            
        }
        bool ans=true;
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                solve(i,i,adj,vis,ans);
            }
        }
        return ans;
    }
};