// TC: O(n)
// SC: O(1)


class Solution {
public:
    int minInsertions(string s) {
        
       int open = 0;
       int ans = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '(')
            {
                open++;
            }
            else {
                if (i + 1 < s.size() && s[i + 1] == ')')
                {
                    i++;
                }
                else
                {
                    ans++;
                }

                if (open > 0)
                {
                    open--;
                } 
                else
                {
                    ans++;
                }
            }
        }

        return ans + open * 2;
    }
};

 
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int minInsertions(string s) {
        
        stack<int>st;
        int ans=0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                if(st.empty() || st.top()==1)
                {
                    st.push(1);
                }
                else if(st.top()==2)
                {
                    ans++;
                    st.pop();
                    st.push(1);
                }
            }
            else{
                if(st.empty())
                {
                    ans++;
                    st.push(2);
                }
                else{
                    st.top()++;
                    if(st.top()==3)
                    {
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty())
        {
            ans+=(3-st.top());
            st.pop();
        }
        return ans;
    }
};

 