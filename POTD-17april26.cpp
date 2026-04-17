class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>freq(26,0);
        for(char ch:s)
        {
            freq[(ch-'a')]++;
        }
        int odd=0;
        for(auto it:freq)
        {
            if(it%2!=0)
            {
                odd++;
            }
            if(odd>1)
            {
                return false;
            }
        }
        return true;
    }
};