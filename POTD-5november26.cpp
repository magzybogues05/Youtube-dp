//solution 1: O(nlogn) time

class Solution {
  public:
  
    bool check(int k, string s, vector<int>& p) {
        for (int i = 0; i < k; i++) {
            s[p[i]] = '?';
        }

        for (int i = 0; i < s.size()-1; i++) 
        {
            if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) 
            {
                return false;
            }
        }

        return true;
    }
    
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int low = 0, high = s.size();
        int ans = high;

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            if(check(mid, s, p))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;

    }
};



//solution 2 : O(n) time

class Solution {
  public:
    
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int day = 0;
        
        int n=s.size();
        for (int i = 0; i < n - 1; i++) 
        {

            if (s[i] != '?' && s[i] == s[i + 1]) 
            {
                
                while (s[i] != '?' && s[i] == s[i + 1]) 
                {
                    s[p[day]] = '?';
                    day++;
                }
            }
        }

        return day;

    }
};