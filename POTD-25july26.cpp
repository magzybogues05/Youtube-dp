class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();

        vector<vector<int>> pref(n, vector<int>(n, 0));
    
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                pref[i][j] = mat[i][j];
                if (i > 0)
                {
                    pref[i][j] += pref[i - 1][j];
                }
                if (j > 0) 
                {
                    pref[i][j] += pref[i][j - 1];
                }
                if (i > 0 && j > 0) 
                {
                    pref[i][j] -= pref[i - 1][j - 1];
                }
            }
        }
    
        int ans = INT_MIN;
    
        for (int i = 0; i + k - 1 < n; i++) 
        {
            for (int j = 0; j + k - 1 < n; j++) 
            {
                int r2 = i + k - 1;
                int c2 = j + k - 1;
    
                int sum = pref[r2][c2];
    
                if (i > 0) 
                {
                    sum -= pref[i - 1][c2];
                }
                if (j > 0)
                {
                    sum -= pref[r2][j - 1];
                }
                if (i > 0 && j > 0) 
                {
                    sum += pref[i - 1][j - 1];
                }
    
                ans = max(ans, sum);
            }
        }
    
        return ans;
    }

};