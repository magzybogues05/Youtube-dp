#define ll long long int
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> freq;
        int one=0;
        for (auto it : nums) 
        {
            if(it==1)
            {
                one++;
            }
            else{
                freq[it]++;
            }
        }

        if(one!=0 && one%2==0)
        {
            one--;
        }
        int ans=one;

        for (auto it : freq)
        {
            ll val = it.first;
            ll base = sqrt(val);

            if ((base*base == val) && freq.count(base) && freq[base] > 1) 
            {
                continue;
            }

            int count = 0;

            while (freq.count(val) && freq[val] > 1) 
            {
                count += 2;
                val=(val*1LL*val);
            }
            if(freq[val]==1)
            {
                count++;
            }
            else{
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};