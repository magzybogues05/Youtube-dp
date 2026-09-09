class Solution {
  public:
  
    int digitSum(int n) 
    {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
  
    int findMax(int n) {
        // code Here
        string s = to_string(n);

        int ans = n;
        int bestSum = digitSum(n);

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '0')
            {
                continue;
            }

            string t = s;

            t[i]--;

            for (int j = i + 1; j < s.size(); j++)
            {
                t[j] = '9';
            }

            int candidate = stoi(t);
            int sum = digitSum(candidate);

            if (sum > bestSum || (sum == bestSum && candidate > ans)) 
            {
                bestSum = sum;
                ans = candidate;
            }
        }

        return ans;
    }
};