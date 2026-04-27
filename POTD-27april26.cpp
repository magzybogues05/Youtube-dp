class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int zero=0;
        int one=0;
        int two=0;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=INT_MAX;
        while(j<n)
        {
            if(s[j]=='0')
            {
                zero++;
            }
            else if(s[j]=='1')
            {
                one++;
            }
            else{
                two++;
            }
            if(zero>0 && one>0 && two>0)
            {
                ans=min(ans,j-i+1);
                while(i<j && (zero>0 && one>0 && two>0))
                {
                    if(s[i]=='0')
                    {
                        zero--;
                    }
                    else if(s[i]=='1')
                    {
                        one--;
                    }
                    else{
                        two--;
                    }
                    ans=min(ans,j-i+1);
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};