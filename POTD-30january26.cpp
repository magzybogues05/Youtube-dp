class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        vector<int>arr(n);
        int i=0;
        while(i<n)
        {
            arr[i]=q.front();
            q.pop();
            i+=2;
        }
        i=1;
        while(i<n)
        {
            arr[i]=q.front();
            q.pop();
            i+=2;
        }
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        
    }
};