class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<pair<int,int>>pref(n);
        for(int i=0;i<n;i++)
        {
            pref[i]={arr[i],arr[i]};
            if(i)
            {
                pref[i].first=max(pref[i].first,pref[i-1].first);
                pref[i].second=min(pref[i].second,pref[i-1].second);
            }
        }
        vector<pair<int,int>>suff(n);
        for(int i=n-1;i>=0;i--)
        {
            suff[i]={arr[i],arr[i]};
            if(i!=n-1)
            {
                suff[i].first=max(suff[i].first,suff[i+1].first);
                suff[i].second=min(suff[i].second,suff[i+1].second);
            }
    
        }
        int ans=INT_MAX;
        for(int i=0;i+k<=n;i++)
        {
            int left_min=(i==0)?INT_MAX:pref[i-1].second;
            int left_max=(i==0)?INT_MIN:pref[i-1].first;
            int right_min=(i+k>=n)?INT_MAX:suff[i+k].second;
            int right_max=(i+k>=n)?INT_MIN:suff[i+k].first;
            int mx=max(right_max,left_max);
            int mn=min(right_min,left_min);
            ans=min(ans,(mx-mn));
        }
        return ans;
    }
};