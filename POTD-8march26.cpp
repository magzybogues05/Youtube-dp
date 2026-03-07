class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int>st;
        for(int a : arr){
            st.insert(a*a);
        }
        for(int a: st)
        {
            for(int b: st)
            {
                if(a != b)
                {
                    if(st.find(a+b)!=st.end())
                    {
                        return true;
                    }
                }
            }
        } 
        return false;
    }
};