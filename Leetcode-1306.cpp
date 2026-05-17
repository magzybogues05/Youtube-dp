class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,-1);
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(arr[curr]==0)
            {
                return true;
            }
            if(curr+arr[curr]<n && vis[curr+arr[curr]]==-1)
            {
                vis[curr+arr[curr]]=1;
                q.push(curr+arr[curr]);
            }
            if(curr-arr[curr]>=0 && vis[curr-arr[curr]]==-1)
            {
                vis[curr-arr[curr]]=1;
                q.push(curr-arr[curr]);
            }
        }
        return false;
    }
};