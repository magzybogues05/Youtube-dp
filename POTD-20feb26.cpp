class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end(),[&](int &a,int &b){
            string aa=to_string(a);
            string bb=to_string(b);
            return (aa+bb)>(bb+aa);
        });
        string ans="";
        for(auto it:arr)
        {
            ans+=to_string(it);
        }
        int idx=-1;
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]=='0')
            {
                idx=i;
            }
            else{
                break;
            }
        }
        
        return ans.substr(idx+1);
    }
};