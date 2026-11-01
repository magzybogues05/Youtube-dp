class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int square = 0;
        int noSquare = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            int curr = arr[i];
            int newNosquare = max(curr, noSquare + curr);
            int newSquare = max(curr*curr, max(noSquare + curr*curr, square + curr));
            noSquare = newNosquare;
            square = newSquare;
            ans = max(ans, max(noSquare, square));
        }
        return ans;
    }
};