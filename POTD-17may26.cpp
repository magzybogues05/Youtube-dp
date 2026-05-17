class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        for(auto it:arr)
        {
            if(ans.size()==0)
            {
                ans.push_back(it);
            }
            else{
                int last=ans[ans.size()-1];
                if((last<0 && it>=0) || (last>=0 && it<0))
                {
                    ans.pop_back();
                }
                else{
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};