class Solution {
  public:

    int longestKSubstr(string &s, int k) {
        // code here
         map<char,int> mp;
        int j = 0;
        int ans = -1;

        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
            
            while(mp.size() > k) {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                {
                    mp.erase(s[j]);
                }
                j++;
            }
            if(mp.size()==k)
            {
                ans= max(ans,i-j+1);
            }

        }
        return ans;
    }
};