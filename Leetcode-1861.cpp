class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));

        for (int r = 0; r < n; r++) {
            int level = m - 1;
            for (int c = m - 1; c >= 0; c--) {
                if (boxGrid[r][c] == '*') {
                    ans[c][n - 1 - r] = '*';
                    level = c - 1;
                }
                else if (boxGrid[r][c] == '#')
                {
                    ans[level][n - 1 - r] = '#';
                    level--;
                }                
            }
        }

        return ans;
    }
};