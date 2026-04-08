class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            while(i<n && arr[i]==0)
            {
                i++;
            }
            while(j>=0 && arr[j]==1)
            {
                j--;
            }
            if(i<j)
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
    }
};