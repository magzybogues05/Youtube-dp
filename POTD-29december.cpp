class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n=a.size();
        int m=b.size();
        if (n > m)
            return kthElement(b, a, k);

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = k - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            }
            else if (leftA > rightB) {
                high = cutA - 1;
            }
            else {
                low = cutA + 1;
            }
        }
        return -1;
    }
};