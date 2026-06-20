class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        if (b == "0") 
        {
            return 1;
        }

        vector<vector<int>> cycle = {
            {0},
            {1},
            {2,4,8,6},
            {3,9,7,1},
            {4,6},
            {5},
            {6},
            {7,9,3,1},
            {8,4,2,6},
            {9,1}
        };

        int d = a[a.size()-1] - '0';
        vector<int> c = cycle[d];

        int len = c.size();

        int rem = 0;
        for (char ch : b)
        {
            rem = (rem * 10 + (ch - '0')) % len;
        }
        if (rem == 0)
        {
            rem = len;
        }
        return c[rem - 1];
    }
};