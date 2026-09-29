class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;

        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;

        q.push({sx, sy});
        visited[sx][sy] = true;

        vector<int> dx{2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dy{1, -1, 1, -1, 2, -2, 2, -2};

        int moves = 0;

        while (!q.empty()) 
        {
            int sz = q.size();

            while (sz--) 
            {
                auto it = q.front();
                q.pop();
                int x=it.first;
                int y=it.second;

                if (x == tx && y == ty)
                {
                    return moves;
                }

                for (int k = 0; k < 8; k++) 
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};