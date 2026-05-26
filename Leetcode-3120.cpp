class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;

        for (char ch : word) 
        {
            if (ch >= 'a' && ch <= 'z') 
            {
                lower |= (1 << (ch - 'a'));
            } 
            else 
            {
                upper |= (1 << (ch - 'A'));
            }
        }

        int ans = lower&upper;
        return __builtin_popcount(ans);
    }
};