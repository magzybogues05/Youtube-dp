class Solution {
public:
    int numberOfSubstrings(string s) {
         map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(i<n)
        {
            mp[s[i]]++;
            if(mp.size()==3)
            {
                ans+=(n-i);
                while(j<i)
                {
                    if(mp[s[j]]==1)
                    {
                        mp.erase(s[j]);
                    }
                    else{
                        mp[s[j]]--;
                    }
                    j++;
                    if(mp.size()==3)
                    {
                        ans+=(n-i);
                    }
                    else{
                        break;
                    }
                    
                }
            }
            i++;
        }
        while(j<i)
        {
            if(mp[s[j]]==1)
            {
                mp.erase(s[j]);
            }
            else{
                mp[s[j]]--;
            }
            if(mp.size()==3)
            {
                ans+=(n-i);
            }
            else{
                break;
            }
            j++;
        }
        
        return ans;
    }
};