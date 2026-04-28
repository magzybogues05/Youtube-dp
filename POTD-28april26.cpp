class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int ans =0;
        int n = s.size();
        for(char ch='A';ch<='Z';ch++){
            int i =0;
            int j = 0;
            int rem = k;
            while(j<n)
            {
                if(s[j] != ch && rem==0)
                {
                    while( i<=j && s[i]==ch)
                    {
                        i++;
                    }
                    i++;
                    rem++;
                }
                if(s[j] != ch && rem >0)
                {
                    rem--;
                }
                ans = max (ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};