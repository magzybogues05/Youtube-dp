class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        map<string,string>mp;
        for(auto it:knowledge)
        {
            mp[it[0]]=it[1];
        }

        string str="";
        string ans="";
        bool flag=false;
        for(char ch:s)
        {
            if(ch=='(')
            {
                flag=true;
            }
            else if(ch==')')
            {
                if(mp.find(str)!=mp.end())
                {
                    ans+=mp[str];
                }
                else{
                    ans+='?';
                }
                flag=false;
                str="";
            }
            else{
                if(flag==true)
                {
                    str+=ch;
                }
                else{
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};