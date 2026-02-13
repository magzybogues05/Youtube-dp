class Solution {
  public:
    
    bool solve(int mid,int d)
    {
        int sum=0;
        int temp=mid;
        while(temp)
        {
            sum+=(temp%10);
            temp/=10;
        }
        return ((mid-sum)>=d);
    }
    
    int getCount(int n, int d) {
        // code here
        int l=0;
        int h=n;
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(solve(mid,d))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==-1)
        {
            return 0;
        }
        return (n-ans+1);
    }
};