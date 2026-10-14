class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        if(sum>(num*9))
        {
            return "";
        }
        string ans="";
        for(int i=0;i<sum/9;i++)
        {
            ans+='9';
        }
        int rem=sum%9;
        if(rem)
        {
            ans+=(rem+'0');
        }
        int remLen= num-ans.size();
        for(int i=0;i<remLen;i++)
        {
            ans+='0';
        }
        return ans;

    }
};