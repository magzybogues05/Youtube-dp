class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[(i+j)].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(auto it:mp)
        {
            for(auto itt:it.second)
            {
                ans.push_back(itt);
            }
        }
        return ans;
    }
};