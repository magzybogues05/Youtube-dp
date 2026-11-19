//Solution 1

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
           if(arr[i]%2==1)
           {
               arr[i]*=-1;
           }
        }

       sort(arr.begin(),arr.end());

       for(int i=0;i<n;i++)
       {
           if(arr[i]<0)
           {
               arr[i]*=-1;
           }
       }

    }
};


//solution-2 (custom comparator)

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        
        sort(arr.begin(), arr.end(), [&](int a, int b) 
            {
              if (a % 2 == b % 2) 
              {
                  if(a%2==0)
                  {
                      return a<b;
                  }
                  else{
                      return a>b;
                  }
              }
              
              return (a % 2 > b % 2);
              
            });

    }
};