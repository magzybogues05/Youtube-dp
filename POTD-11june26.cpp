class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int close=0;
        for(char ch:s)
        {
            if(ch==')')
            {
                close++;
            }
        }
        int o=0;
        int c=0;
        if(close==0)
        {
            return 0;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                o++;
            }
            else{
                c++;
            }
            if(o==(close-c))
            {
                return i+1;
            }
        }
        return -1;
    }
};