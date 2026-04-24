class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int d=0;
        for(char ch:moves)
        {
            if(ch=='L')
            {
                l++;
            }
            else if(ch=='R')
            {
                r++;
            }
            else{
                d++;
            }
        }
        int ans=max(l+d-r,r+d-l);
        return ans;
    }
};