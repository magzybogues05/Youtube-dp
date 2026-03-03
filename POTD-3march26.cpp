class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        map<int,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
            while(mp.size()>2)
            {
                mp[arr[j]]--;
                if(mp[arr[j]]==0)
                {
                    mp.erase(arr[j]);
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};