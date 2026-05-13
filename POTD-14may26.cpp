class Solution {
  public:
  
    vector<int>  calculateZ(vector<int> &input) {
        vector<int>Z(input.size(),0);
        int left = 0;
        int right = 0;
        for(int k = 1; k <(int) input.size(); k++) {
            if(k > right) {
                left = right = k;
                while(right < input.size() && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                int k1 = k - left;
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { 
                    left = k;
                    while(right < input.size() && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
  
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int m=b.size();
        b.push_back(INT_MAX);
        for(auto it:a)
        {
            b.push_back(it);
        }
        vector<int>ans;
        vector<int>z=calculateZ(b);
        for(int i=m+1;i<b.size();i++)
        {
            if(z[i]==m)
            {
                ans.push_back(i-(m+1));
            }
        }
        return ans;
    }
};