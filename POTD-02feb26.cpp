class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int sum=0;
        int totalsum=0;
        int negsum=0;
        int mx=0;
        int mn=0;
        int ans=*max_element(arr.begin(),arr.end());
        if(ans<0)
        {
            return ans;
        }
        for(auto it:arr)
        {
            totalsum+=it;
            sum+=it;
            mx=max(mx,sum);
            sum=max(0,sum);
            negsum+=(-1*it);
            mn=max(mn,negsum);
            negsum=max(0,negsum);
        }
        ans=max(mx,totalsum+mn);
        return ans;
    }
};