class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int pbs=-1*arr[0];
        int pss=0;
        for(int i=1;i<n;i++)
        {
            //buy state
            int tbs=max(pbs,pss-arr[i]);

            //sell state
            int tss= max(pss, pbs+arr[i]-k);

            pbs=tbs;
            pss=tss;
        }

        return pss;
    }
};