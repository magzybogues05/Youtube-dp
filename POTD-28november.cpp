class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int xorr=0;
        for(int i=1;i<=n;i++)
        {
            xorr^=i;
        }
        vector<int>ans;
        int missing=-1;
        if(xorr!=n)
        {
            missing=(n^xorr);
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=missing)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
