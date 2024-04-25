class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans=0;
        if(n<3 || m<3)
        {
            return -1;
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int sum=mat[i][j]+mat[i-1][j]+mat[i+1][j]+mat[i-1][j-1]+mat[i+1][j-1]+mat[i+1][j+1]+mat[i-1][j+1];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};