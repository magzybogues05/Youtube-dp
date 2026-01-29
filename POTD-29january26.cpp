class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n = s.size();
        int j = 0;
        vector<int>freq(26,0);
        string ans="";
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
            while(j <= i && freq[s[j]-'a'] > 1)
            {
                j++;
            }
            if(j>i)
            {
                ans+='#';
            }
            else{
                ans+=s[j];
            }
        } 
        return ans;
    }
};