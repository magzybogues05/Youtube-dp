class Solution {
  public:
    
    string sum(string &a,string &b)
    {
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int temp=(a[i]-'0')+(b[j]-'0')+carry;
           int rem=(temp%10);
            ans=char(rem+'0')+ans;
            carry=temp/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            int temp=(a[i]-'0')+carry;
            int rem=(temp%10);
            ans=char('0'+rem)+ans;
            carry=temp/10;
            i--;
        }
        while(j>=0)
        {
            int temp=(b[j]-'0')+carry;
            int rem=(temp%10);
            ans=char('0'+rem)+ans;
            carry=temp/10;
            j--;
        }
        if(carry)
        {
        ans=char(carry+'0')+ans;
        }
        return ans;
    }
  
    bool isAdditiveSequence(string str) {
        // Your code here
        int n=str.size();
        string first="";
        for(int i=0;i<n/2;i++)
        {
            first+=str[i];
            string sec="";
            for(int j=i+1;j<n-1;j++)
            {
                sec+=str[j];
                bool flag=true;
                int k=j+1;
                string f=first;
                string s=sec;
                while(k<n)
                {
                    string t=sum(f,s);
                    int tsize=t.size();
                    tsize=min(tsize,(n-k));
                    string newstring=str.substr(k,tsize);
                    if(newstring!=t)
                    {
                        flag=false;
                        break;
                    }
                    else{
                        f=s;
                        s=t;
                        k+=tsize;
                    }
                }
                if(flag==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};