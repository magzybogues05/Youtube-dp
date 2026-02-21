class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int ans = 0;
        int n = citations.size();
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0; i<n; i++){
            if(citations[i]>=(i+1)){
                ans=i+1;
            }
        }
        return ans;
    }
};