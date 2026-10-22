class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        
        int ans=0;
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]=='?' && s[n-i-1]!='?')
            {
                s[i]=s[n-i-1];
            }
            else if(s[i]!='?' && s[n-i-1]=='?')
            {
                s[n-i-1]=s[i];
            }
            
            if(s[i]!=s[n-i-1])
            {
                return -1;
            }
        }
        
        char prev='?';
        for(int i=0;i<=n/2;i++)
        {
            if(prev=='?')
            {
                if(s[i]!='?')
                {
                    prev=s[i];
                }
            }
            else if(s[i]!='?')
            {
                ans+=abs(s[i]-prev);
                prev=s[i];
            }
        }
        return ans*2;
    }
};