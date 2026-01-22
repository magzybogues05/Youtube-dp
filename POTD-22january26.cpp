#define ll long long int
class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>prevGreater(n,0);
        vector<int>nextGreater(n,0);
        vector<int>prevSmaller(n,0);
        vector<int>nextSmaller(n,0);
        stack<int>st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]<=arr[i])
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
        stack<int>st3;
        for(int i=0;i<n;i++)
        {
            while(!st3.empty() && arr[st3.top()]>=arr[i])
            {
                st3.pop();
            }
            if(st3.empty())
            {
                prevSmaller[i]=-1;
            }
            else{
                prevSmaller[i]=st3.top();
            }
            st3.push(i);
        }
        
        stack<int>st4;
        for(int i=n-1;i>=0;i--)
        {
            while(!st4.empty() && arr[st4.top()]>arr[i])
            {
                st4.pop();
            }
            if(st4.empty())
            {
                nextSmaller[i]=n;
            }
            else{
                nextSmaller[i]=st4.top();
            }
            st4.push(i);
        }
        ll totalmx=0;
        ll totalmn=0;
        for(int i=0;i<n;i++)
        {
            ll leftSmallerCount = i-prevGreater[i];
            ll rightSmallerCount = nextGreater[i]-i;
            totalmx+=arr[i]*1LL*leftSmallerCount*rightSmallerCount;
            
            ll leftGreaterCount = i-prevSmaller[i];
            ll rightGreaterCount = nextSmaller[i]-i;
            totalmn+= arr[i]*1LL*leftGreaterCount*rightGreaterCount;
            
        }
        return totalmx-totalmn;
    }
};