class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx= *max_element(costs.begin(),costs.end());
        vector<int> freq(mx+1, 0);

        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        for (int cost = 1; cost <= mx; cost++) 
        {
            if(coins < cost) 
            {
                break;
            }
            if (freq[cost] == 0)
            {
                continue;
            }

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }

        return count;
    }
};