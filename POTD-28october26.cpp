class Solution {
  public:
    char nthCharacter(int n) {
        // code here
        long long digits = 1;
        long long start = 1;
        long long count = 9;

        while (n > (count * digits)) 
        {
            n -= (count * digits);
            digits++;
            start *= 10;
            count *= 10;
        }

        long long num = start + (n - 1) / digits;
        int pos = (n - 1) % digits;
        string s = to_string(num);
        
        return s[pos];
    }
};