class Solution {
public:
    int numberOfSpecialChars(string word) {
        int upper=0;
        int lower=0;
        int n=word.size();
        for(int i=n-1;i>=0;i--)
        {
            if(word[i]>='a' && word[i]<='z')
            {
                lower|=(1<<(word[i]-'a'));
            }
            else
            {
                int ch=word[i]-'A';
                if(lower&(1<<ch))
                {
                    upper&=(~(1<<ch));
                }
                else{
                    upper|=(1<<ch);
                }
            }
        }
        int ans=lower&upper;
        return __builtin_popcount(ans);
    }
};