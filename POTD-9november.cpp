class Solution {
  public:
    int dp[51][51][51];
    int solve(int r1,int c1,int r2,int n,vector<vector<int>>&mat)
    {
        int c2=r1+c1-r2;
        if(r1<0 || c1<0 || r2<0 || c2<0 || r1>=n || c1>=n || r2>=n || c2>=n || mat[r1][c1]==-1 || mat[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(r1==n-1 && c1==n-1) {
            return mat[r1][c1];
        }
        if(dp[r1][c1][r2]!=-1) 
        {
            return dp[r1][c1][r2];
        }
        int ans=0;
        if(r1==r2 && c1==c2){
            ans+=mat[r1][c1];
        }else{
            ans+=mat[r1][c1]+mat[r2][c2];
        }
        int d1=solve(r1+1,c1,r2+1,n,mat);
        int d2=solve(r1,c1+1,r2,n,mat);
        int d3=solve(r1+1,c1,r2,n,mat);
        int d4=solve(r1,c1+1,r2+1,n,mat);
        int d=max({d1,d2,d3,d4});
        if(d==INT_MIN)
        {
            ans=INT_MIN;
        }
        else{
            ans+=d;
        }
        return dp[r1][c1][r2]=ans;
        
    }
  
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        memset(dp,-1,sizeof dp);
        int n=mat.size();
        int ans=solve(0,0,0,n,mat);
        return max(0,ans);
    }
};
