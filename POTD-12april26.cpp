class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        map<int,set<int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].insert(mat[i][j]);
                if(mp[i-j].size()>1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};