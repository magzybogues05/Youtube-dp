class Solution {
  public:
        
    bool solve(int i,int j,int idx,vector<vector<char>>&mat,string &word,vector<int>&da,vector<int>&db)
    {
        if(idx==word.size())
        {
            return true;
        }
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]!=word[idx])
        {
            return false;   
        }
        char ch=mat[i][j];
        mat[i][j]='#';
        for(int d=0;d<4;d++)
        {
            int ni=i+da[d];
            int nj=j+db[d];
            if(solve(ni,nj,idx+1,mat,word,da,db))
            {
                return true;
            }
        }
        mat[i][j]=ch;
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>da{0,0,-1,1};
        vector<int>db{-1,1,0,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==word[0])
                {
                    bool flag=solve(i,j,0,mat,word,da,db);
                    if(flag)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};