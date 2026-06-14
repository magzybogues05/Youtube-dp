class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
    
        int i = 0, j = 0;
        int d = 0;
    
        while (i >= 0 && i < n && j >= 0 && j < m) {
    
            if (mat[i][j] == 1) {
                d = (d + 1) % 4;
                mat[i][j] = 0;
            }
    
            if (d == 0)
            {
                j++;
            }
            else if (d == 1)
            {
                i++;
            }
            else if (d == 2)
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    
        if (d == 0)
        {
            j--;
        }
        else if (d == 1)
        {
            i--;
        }
        else if (d == 2)
        {
            j++;
        }
        else
        {
            i++;
        }
    
        return {i, j};
    }
};