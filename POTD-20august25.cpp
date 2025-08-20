#define ll long long int
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        ll l=0;
        ll r=n*m-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            ll row=mid/m;
            ll col=mid%m;
            ll val=mat[row][col];
            if(val==x)
            {
                return true;
            }
            ll lowVal=mat[l/m][l%m];
            ll highVal=mat[r/m][r%m];
            
            if(lowVal <= val) {
                if (lowVal <= x && x < val)
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (val < x && x <= highVal)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
