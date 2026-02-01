class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && arr[dq.back()]<arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=(k-1))
            {
                while(!dq.empty() && dq.front()<=(i-k))
                {
                    dq.pop_front();
                }
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};