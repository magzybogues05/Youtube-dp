class Solution {
public:
    
    void solve(int i,vector<int>adj[],vector<int>&vis,set<int>&temp)
    {
        for(auto it:adj[i])
        {
            if(vis[it]==-1)
            {
                vis[it]=1;
                temp.insert(it);
                solve(it,adj,vis,temp);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<int>adj[n];
        for(auto it:invocations)
        {
            adj[it[0]].push_back(it[1]);
        }
        set<int>temp;
        temp.insert(k);
        vector<int>ans;
        vector<int>vis(n,-1);
        vis[k]=1;
        solve(k,adj,vis,temp);
        for(int i=0;i<n;i++)
        {
            if(temp.find(i)==temp.end())
            {
                for(auto it:adj[i])
                {
                    if(temp.find(it)!=temp.end())
                    {
                        for(int j=0;j<n;j++)
                        {
                            ans.push_back(j);
                        }
                        return ans;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(temp.find(i)==temp.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};