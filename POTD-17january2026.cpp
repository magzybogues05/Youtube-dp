class Solution {
  public:
  
    bool isOperator(char ch)
    {
        if((ch=='+') || (ch=='-') || (ch=='/') || (ch=='*'))
        {
            return true;
        }
        return false;
    }
    bool checkRedundancy(string &s) {
        // code here
         stack<pair<char,int>>st;
         for(char ch:s)
         {
             if(ch=='(')
             {
                 st.push({'(',0});
             }
             else if(isOperator(ch))
             {
                 if(!st.empty())
                 {
                     st.top().second++;
                 }
             }
             else if(ch==')')
             {
                 if(st.empty())
                 {
                     return true;
                 }
                 else{
                     if(st.top().second==0)
                     {
                         return true;
                     }
                     else{
                         st.pop();
                     }
                 }
             }
         }
         return false;
    }
};
