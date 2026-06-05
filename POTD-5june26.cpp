class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        if(!(n&(n-1)))
        {
            k>>=1;
        }
        else
        {
            k<<=1;
        }
        if(k>=n)
        {
            return "-1";
        }
        string ans;
        for(auto it:s)
        {
            while(ans.size()!=0 && ans[ans.size()-1]>it && k>0)
            {
                ans.pop_back();
                k--;
            }
            ans+=it;
        }
        while(k)
        {
            k--;
            ans.pop_back();
        }
        return ans;
    }
};