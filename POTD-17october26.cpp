class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m= s2.size();
        int i = 0;
        int j = 0;

        while (i < n && j < m) 
        {
            while (i < n && s1[i] == '#') 
            {
                i++;
            }
            while (j < m && s2[j] == '#') 
            {
                j++;
            }

            if (i == n || j == m)
            {
                return ((i == n) && (j == m));
            }

            if (s1[i] != s2[j])
            {
                return false;
            }

            if (s1[i] == 'A' && j > i)
            {
                return false;
            }

            if (s1[i] == 'B' && j < i)
            {
                return false;
            }

            i++;
            j++;
        }

        while (i < n && s1[i] == '#') 
        {
            i++;
        }
        while (j < m && s2[j] == '#')
        {
            j++;
        }

        return ((i == n) && (j == m));
    }
};