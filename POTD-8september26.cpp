class Solution {
  public:
    
    bool valid(int x, int y, vector<vector<char>>&mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
  
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {

                if (mat[i][j] != word[0])
                {
                    continue;
                }

                for (int d = 0; d < 8; d++) 
                {

                    int x = i;
                    int y = j;
                    int k = 0;

                    while (k < word.size()) 
                    {
                        if (!valid(x, y, mat) || mat[x][y] != word[k])
                        {
                            break;
                        }

                        x += dx[d];
                        y += dy[d];
                        k++;
                    }

                    if (k == word.size()) 
                    {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};