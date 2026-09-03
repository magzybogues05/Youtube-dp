class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int keep = 0;
        int replace = 0;

        for (int i = 1; i < arr.size(); i++) 
        {
            int newKeep = max(
                keep + abs(arr[i] - arr[i - 1]),
                replace + abs(arr[i] - 1)
            );

            int newReplace = max(
                keep + abs(1 - arr[i - 1]),
                replace
            );

            keep = newKeep;
            replace = newReplace;
        }

        return max(keep, replace);
    }
};