class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int count=0;
        
        for(char ch:s)
        {
            if(count==0 && ch=='y')
            {
                return false;
            }
            if(ch=='x')
            {
                count++;
            }
            else{
                count--;
            }
        }
        return (count==0);
    }
};