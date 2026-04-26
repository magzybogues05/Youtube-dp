class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int n=a.size();
        int m=b.size();
        int o=c.size();
        int i=0;
        int j=0;
        int k=0;
        vector<int>ans;
        while(i<n && j<m && k<o)
        {
            if(a[i]==b[j] && b[j]==c[k])
            {
                ans.push_back(a[i]);
                int curr=a[i];
                i++;
                j++;
                k++;
                while(i<n && a[i]==curr)
                {
                    i++;
                }
                while(j<m && b[j]==curr)
                {
                    j++;
                }
                while(k<o && c[k]==curr)
                {
                    k++;
                }
            }
            else{
                int mn=min({a[i],b[j],c[k]});
                if(a[i]==mn)
                {
                    i++;
                }
                if(b[j]==mn)
                {
                    j++;
                }
                if(c[k]==mn)
                {
                    k++;
                }
            }
        }
        return ans;
    }
};