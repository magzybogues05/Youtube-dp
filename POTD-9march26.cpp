class Solution {
  public:
    string largestSwap(string &s) 
    {
        int n = s.size();
        int mx = n-1;
        int left = -1, right = -1;
    
        for(int i = n-2; i >= 0; i--)
        {
            if(s[i] > s[mx])
            {
                mx = i;
            }
            else if(s[i] < s[mx])
            {
                left = i;
                right = mx;
            }
        }
    
        if(left != -1)
        {
            swap(s[left], s[right]);
        }
    
        return s;
    }
};