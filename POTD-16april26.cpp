class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        long ans=0;
        char sign=' ';
    
        for(char a : s){
            if(a<='9' && a>='0'){
                ans*=10;
                ans+=(a-'0');
            }
            else{
                if(ans!=0 || sign!=' ')
                {
                    break;
                }
                if(ans==0 && sign==' '){
                    if(a=='-' || a=='+')
                    {
                        sign=a;
                    }
                    else if(a==' ')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(ans>INT_MAX && sign=='-' )
            {
                return INT_MIN;
            }
            if(ans>INT_MAX) 
            {
                return INT_MAX;
            }
        }
        if(sign == '-')
        {
          return -1*ans;  
        }
        return ans;
    }
};
