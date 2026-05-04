#define ll long long int
class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        ll temp=N;
        ll rev=0;
        while(temp)
        {
            if(temp&1)
            {
                rev|=1;
            }
            temp>>=1;
            if(temp)
            {
                rev<<=1;
            }
        }
        return (N==rev);
    }
};