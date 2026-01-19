class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        stack<char>st;
        for(char ch:s)
        {
            while(!st.empty() && (st.top()>ch) && (k>0))
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        int idx=-1;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!='0')
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
        {
            return "0";
        }
        return ans.substr(idx);
    }
};