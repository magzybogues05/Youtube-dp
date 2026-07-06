class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n=a.size();
        int m=b.size() ;
        int i=0;
        int j=0;
        int sum1=0;
        int sum2=0;
        while((i < n) && (j < m))
        {
            if(a[i] < b[j])
            {
                sum1 += a[i];
                i++;
            }
            else if(a[i] > b[j])
            {
                sum2 += b[j];
                j++;
            }
            else
            {
                sum1 = max(sum1,sum2) + a[i];
                sum2 = sum1;
                i++;
                j++;
            }
        }
        
         while (i < n)
         {
            sum1 += a[i];
            i++;
         }

        while (j < m)
        {
            sum2 += b[j];
            j++;
        }
        return max(sum1,sum2);
    }
};