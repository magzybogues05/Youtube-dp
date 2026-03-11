class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        vector<int>pse(n,-1);
        int ans=0;
        stack<int>st2;
        for(int i=0;i<n;i++)
        {
            while(!st2.empty() && arr[st2.top()] > arr[i]) {
                st2.pop();
            }
            if(!st2.empty())
            {
                pse[i]=st2.top();
            }
            st2.push(i);
        }
        
        for(int i=n-1;i>=0;i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            int nextSmaller=st.empty() ? n : st.top();
            int prevSmaller= pse[i];
            ans+=((i-prevSmaller)*(nextSmaller-i))*arr[i];
            st.push(i);
        }
        
        return ans;
    }
};