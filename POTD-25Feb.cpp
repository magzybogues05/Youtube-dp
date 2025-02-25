class Solution {
    public:
      int getMaxArea(vector<int> &heights) {
          int n=heights.size();
          stack<int> st;
          vector<int> nsl(n,0);
          for(int i=0;i<n;i++)
          {
              if(st.empty())
              {
                  nsl[i]=-1;
              }
              else if(heights[i]>heights[st.top()])
              {
                  nsl[i]=st.top();
              }
              else{
                  while(!st.empty() && heights[i]<=heights[st.top()])
                  {
                      st.pop();
                  }
                  if(st.empty())
                  {
                      nsl[i]=-1;
                  }
                  else{
                      nsl[i]=st.top();
                  }
              }
              st.push(i);
          }
          stack<int> stt;
          vector<int> nsr(n,0);
          for(int i=n-1;i>=0;i--)
          {
              if(stt.empty())
              {
                  nsr[i]=n;
              }
              else if(heights[i]>heights[stt.top()])
              {
                  nsr[i]=stt.top();
              }
              else{
                  while(!stt.empty() && heights[i]<=heights[stt.top()])
                  {
                      stt.pop();
                  }
                  if(stt.empty())
                  {
                      nsr[i]=n;
                  }
                  else{
                      nsr[i]=stt.top();
                  }
              }
              stt.push(i);
          }
          long long int ans=0;
          for(int i=0;i<n;i++)
          {
              int width=nsr[i]-nsl[i]-1;
              int height=heights[i];
              ans=max(ans,width*height*1LL);
          }
          return ans;
      }
  };