//User function Template for C++

class Solution{
    public:
    bool wifiRange(string S, int X){
        // code here
        int z=0;
        bool flag=false;
        int N=S.size();
        for(int i=0;i<N;i++)
        {
            if(S[i]=='0')
            {
                z++;
            }
            else{
                if(flag)
                {
                    if(z>(2*X))
                    {
                        return false;
                    }
                }
                else{
                    if(z>X)
                    {
                        return false;
                    }
                }
                z=0;
                flag=true;
            }
        }
        if(flag==false || z>X)
        {
            return false;
        }
        return true;
    }
};