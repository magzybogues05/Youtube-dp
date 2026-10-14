class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        
        int n=s.size();
        vector<int>pref(n,0);
        
        for(auto it:roll)
        {
            pref[0]++;
            if(it!=n)
            {
                pref[it]--;
            }
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                pref[i]+=pref[i-1];
            }
            
            ans+= ('a'+ ((s[i]-'a')+pref[i])%26);
        }
        return ans;
        
    }
};