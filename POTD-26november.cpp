class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int count=0;
        while(l!=r)
        {
            l>>=1;
            r>>=1;
            count++;
        }
        return (l<<count);
        
    }
};
