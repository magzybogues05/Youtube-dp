class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int ans=0;
        int zero=0;
        int one=0;
        int n=arr.size();
        for (int i=0; i<n; i++){
            if (arr[i]==0) {
                zero++;
            }
            else{
                zero--;
                one++;
            }
            ans=max(zero, ans);
            zero=max(zero,0);
        }
        return ans+one;
    }
};