class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int ans = 0;
        int sum = 0;
        int curr = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(char ch:s)
        {
            if(ch=='0')
            {
                sum--;
            }
            else{
                sum++;
            }
            if(ch=='0')
            {
                curr-= mp[sum];
            }
            else{
                curr+=mp[sum-1];
            }
            ans += curr;
            mp[sum]++;
        }
        return ans;
    }
};