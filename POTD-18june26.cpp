class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            bool seen = false;
            for (int j = 0; j < m; j++) 
            {
                if (seen)
                {
                    mat[i][j] |= (1 << 1);
                }
                if (mat[i][j] & 1) 
                {
                    seen = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            bool seen = false;
            for (int j = m - 1; j >= 0; j--) 
            {
                if (seen)
                {
                    mat[i][j] |= (1 << 2);
                }
                if (mat[i][j] & 1)
                {
                    seen = true;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            bool seen = false;
            for (int i = 0; i < n; i++) {
                if (seen)
                {
                    mat[i][j] |= (1 << 3);
                }
                if (mat[i][j] & 1)
                {
                    seen = true;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            bool seen = false;
            for (int i = n - 1; i >= 0; i--) {
                if (seen)
                {
                    mat[i][j] |= (1 << 4);
                }
                if (mat[i][j] & 1)
                {
                    seen = true;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if ((mat[i][j] & 1) == 0) 
                {
                    ans += ((mat[i][j] >> 1) & 1);
                    ans += ((mat[i][j] >> 2) & 1);
                    ans += ((mat[i][j] >> 3) & 1);
                    ans += ((mat[i][j] >> 4) & 1);
                }
            }
        }

        return ans;
    }
};