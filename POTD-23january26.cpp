class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>prevGreater(n,0);
        vector<int>nextGreater(n,0);
        stack<int>st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]<arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                prevGreater[i]=-1;
            }
            else{
                prevGreater[i]=st1.top();
            }
            st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]<arr[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                nextGreater[i]=n;
            }
            else{
                nextGreater[i]=st2.top();
            }
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int left=(nextGreater[i]-i-1);
            int right=(i-prevGreater[i]-1);
            ans= max(ans,left+right+1);
            
        }
        return ans;
    }
};