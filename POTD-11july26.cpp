class Solution {
  public:
  
     int solve(int i,int j,int x,int y,vector<vector<int>>&mat,vector<vector<bool>>&vis)
     {
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j] || mat[i][j]==0)
        {
            return INT_MIN;
        }
        
        if(i==x && j==y)
        {
            return 0;
        }
        
        vis[i][j]=true;
        
        int left = solve(i,j-1,x,y,mat,vis);
        int right = solve(i,j+1,x,y,mat,vis);
        int up = solve(i-1,j,x,y,mat,vis);
        int down = solve(i+1,j,x,y,mat,vis);
        
        int ans=max({left,right,up,down});
        
        vis[i][j]=false;
        
        if(ans==INT_MIN)
        {
            return ans;
        }
        return ans+1;
        
    }
  
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans = solve(xs,ys,xd,yd,mat,vis);
        if(ans==INT_MIN)
        {
            return -1;
        }
        return ans;
    }
};