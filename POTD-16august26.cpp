#define ll long long int
class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int negative = 0;
        ll product = 1;
        int largestNegative = INT_MIN;

        bool hasZero = false;
        int smallestPositive = INT_MAX;

        for (int x : arr) {
            if (x < 0) 
            {
                negative++;
                product *= x;
                largestNegative = max(largestNegative, x);
            } 
            else if (x == 0) 
            {
                hasZero = true;
            }
            else {
                product *=x;
                smallestPositive = min(smallestPositive, x);
            }
        }

        if (negative == 0) 
        {
            return hasZero ? 0 : smallestPositive;
        }

        if (negative % 2 == 1) 
        {
            return product;
        }

        if (negative) 
        {
            return product / largestNegative;
        }

        return 0;

    }
};