class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int count=0;
        map<int,int>mp;
        int val=0;
        for(int i=1;i<=arr.size();i++)
        {
            if(arr[i-1]!=i)
            {
                count++;
                mp[arr[i-1]]=i;
                val=arr[i-1];
                if(count>4)
                {
                    return false;
                }
            }
        }
        if(count==3 || count==0)
        {
            return true;
            
        }
        if(count==2 || count>4)
        {
            return false;
        }
        if(mp[mp[val]]==val)
        {
            return true;
        }
        return false;
    }
};