#define ll long long int
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<ll>s;
         for(int i=0;i<arr.size();i++)
         {
            if(arr[i]==0)
            {
                if(target == 0)
                {
                    return true;
                }
                continue;
            }
            if(target % arr[i] == 0)
            {
                ll need = target/arr[i];
                if(s.find(need) !=s.end())
                {
                    return true;
                }
            }
            s.insert(arr[i]);
        }
        return false;
    }
};