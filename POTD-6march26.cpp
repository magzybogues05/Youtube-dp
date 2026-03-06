class Solution {
  public:
    
     bool equal(map<int,int> &mp1, map<int,int> &mp2) {
        for (auto i:mp1) {
            if (i.second> mp2[i.first]) return false;
        }
        return true;   
    }
  
    string minWindow(string &s, string &p) {
        // code here
        map<int,int> mp1, mp2;
        int a = 0, b = s.size()+1;
        for (char ch:p)
        {
            mp1[ch]++;
        }
        int n = s.size();
        int l =0,r = 0;
        while(r<=n) {
            if (equal(mp1,mp2)) {
                if (r-l<b-a) {
                    a= l;
                    b =r;
                }
                mp2[s[l]]--;
                if (!mp2[s[l]]) mp2.erase(s[l]);
                l++;
            }
            else {
                mp2[s[r]]++;
                r++;
            }      
        }
        if (b-a+1>n) return "";
        return s.substr(a,b-a);
    }
};