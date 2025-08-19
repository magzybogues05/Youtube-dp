class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>suff(n,0);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=min(arr[i],suff[i+1]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(suff.begin(),suff.end(),arr[i]);
            if(it==arr.begin())
            {
                ans.push_back(-1);
            }
            else{
                --it;
                int idx=it-suff.begin();
                if(idx>i)
                {
                    ans.push_back(idx);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};