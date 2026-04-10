class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
         int n = arr.size();
        if (n < 3) return {};
    
        int first = INT_MAX, second = INT_MAX;
        int potential_first = INT_MAX;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] <= potential_first) {
                potential_first = arr[i];
            }
            else if (arr[i] <= second) {
                first = potential_first;
                second = arr[i];
            }
            else {
                return {first, second, arr[i]};
            }
        }
    
        return {};
        
    }
};