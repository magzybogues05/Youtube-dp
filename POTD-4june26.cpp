class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int sum1=0;
        int ans=0;
        int one=0;
        for(char ch:s)
        {
            if(ch=='1')
            {
                sum1--;
                one++;
            }
            else{
                sum1++;
            }
            ans=max(ans,sum1);
            sum1=max(0,sum1);
        }
        if(one==s.size())
        {
            return -1;
        }
        return ans;
    }
};