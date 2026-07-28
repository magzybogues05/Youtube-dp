class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        string a="";
        char ch='1';
        for(auto it:mp)
        {
            if(it.second%2==1)
            {
                ch=it.first;
            }
            for(int c=0;c<it.second/2;c++)
            {
                a+=it.first;
            }

        }
        string ans=a;
        if(ch!='1')
        {
            ans+=ch;
        }
        reverse(a.begin(),a.end());
        ans+=a;
        return ans;
    }
};