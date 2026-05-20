class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int common = 0;
        vector<int>ans;
        int n=A.size();
        for (int i = 0; i < n; i++) 
        {
            
            int x = abs(A[i]);
            int y = abs(B[i]);

            if (x == y) 
            {
                common++;
            }
            else
            {
                if(B[x - 1] < 0)
                {
                    common++;
                }
                A[x - 1] *= -1;

                if(A[y - 1] < 0)
                {
                    common++;
                }

                B[y - 1] *= -1;
            }
            ans.push_back(common);
        }

        return ans;
    }
};