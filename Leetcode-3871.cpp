class Solution {
public:
    long long countCommas(long long n) {
        
        long long ans = 0;
        long long start = 1;

        for (int digit = 1; digit <= 16; digit++) {
            if (start > n) break;
            long long end = min(n ,(start*10)-1);
            long long count = end-start+1;
            long long comma = (digit-1)/3;
            ans += (count*comma);
            start=start*10;
        }
        return ans;
    }
};