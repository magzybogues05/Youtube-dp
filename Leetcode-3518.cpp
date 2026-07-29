#define ll long long int
class Solution {
public:
    int ncr(int n, int r, int k) {
        if (r > n - r) 
        {
            r = n - r;
        }
        long long res = 1;
        for (int i = 1; i <= r; i++) 
        {
            res = res * (n - i + 1) / i;
            if (res >= k)
            {
                return k;
            }
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        
        int n=s.size();
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        vector<int>half(26,0);
        char ch='1';
        for(auto it:mp)
        {
            if(it.second%2==1)
            {
                ch=it.first;
            }
            half[it.first-'a']=it.second/2;
        }
        string result = "";
        for (int i = 0; i <(n/2) ; i++) 
        {
            for(int j=0;j<26;j++)
            {
                if(half[j]!=0)
                {
                    ll ways=1;
                    ll total=(n/2-i-1);
                    half[j]--;
                    for(int c=0;c<26;c++)
                    {
                        if(half[c]!=0)
                        {
                            ways*=ncr(total,half[c],k);
                            total-=half[c];
                        }
                        if(ways>=k)
                        {
                            break;
                        }
                    }
                    if(ways>=k)
                    {
                        result+=('a'+j);
                        break;
                    }
                    else{
                        k-=ways;
                        half[j]++;
                    }
                }
                
                
            }

        }
        if(result.size()!=(n/2))
        {
            return "";
        }
        string ans=result;
        if(ch!='1')
        {
            ans+=ch;
        }
        reverse(result.begin(),result.end());
        ans+=result;
        return ans;
    }
};