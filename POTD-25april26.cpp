class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int>st;
        for (int x : arr) 
        {
            st.push_back(x);
            while (st.size()>=2) 
            {
                int top = st[st.size()-1];
                int second=st[st.size()-2];
                if(top*second<0)
                {
                    st.pop_back();
                    st.pop_back();
                    if(abs(top)==abs(second))
                    {
                        continue;
                    }
                    else if(abs(top)>abs(second))
                    {
                        st.push_back(top);
                    }
                    else{
                        st.push_back(second);
                    }
                }
                else{
                    break;
                }
            }
        }

        return st;
    }
};