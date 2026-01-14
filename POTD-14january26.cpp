class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int p=0;
        int t=0;
        int ans=0;
        int n=arr.size();
        while(p < n && t < n)
        {
            while(p < n && arr[p] != 'P')
            {
                p++;
            }
            while(t < n && arr[t] != 'T')
            {
                t++;
            }
            if(p < n && t < n)
            {
                if(abs(t - p) <= k)
                { 
                    ans++;
                    t++;
                    p++;
                }
                else{
                    if(p>t)
                    { 
                        t++;
                    }
                    else{
                        p++;
                    }
                }
            } 
        }
        return ans;
    }
};