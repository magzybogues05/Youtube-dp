class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n=a1.size();
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=-1;
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=a1[i];
            sum2+=a2[i];
            int diff=sum2-sum1;
            if(mp.find(diff)!=mp.end())
            {
                ans=max(ans,(i-mp[diff]));
            }
            else{
                mp[diff]=i;
            }
        }
        return ans;
    }
};

