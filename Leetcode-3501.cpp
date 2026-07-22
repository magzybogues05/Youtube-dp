class SegTree{
public:
    int n;
    vector<int> tree;

    SegTree(vector<int> &arr){
        n=1;
        while(n<arr.size()) n<<=1;

        tree.assign(2*n,0);

        for(int i=0;i<arr.size();i++)
            tree[n+i]=arr[i];

        for(int i=n-1;i>=1;i--)
            tree[i]=max(tree[2*i],tree[2*i+1]);
    }

    int query(int l,int r){
        l+=n;
        r+=n;

        int res=0;

        while(r-l>1){
            if(!(l&1))
                res=max(res,tree[l+1]);
            if(r&1)
                res=max(res,tree[r-1]);

            l>>=1;
            r>>=1;
        }

        return res;
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> flip;

        int ones=1;
        if (s[0] == '0')
        {
            flip.push_back(0);
            ones--;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                flip.push_back(i);
            }
            if(s[i]=='1')
            {
                ones++;
            }
        }

        if (s[n - 1] == '0')
        {
            flip.push_back(n);
        }

        // gain = leftZero + rightZero
        vector<int> gain;
        for (int j = 3; j < flip.size(); j += 2)
        {
            gain.push_back((flip[j] - flip[j - 1]) + (flip[j - 2] - flip[j - 3]));
        }

        SegTree seg(gain);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int lPos = lower_bound(flip.begin(), flip.end(), l + 1) - flip.begin();
            int rPos = lower_bound(flip.begin(), flip.end(), r + 1) - flip.begin();

            int change = 0;

            if ((rPos - lPos < 2) || (rPos - lPos == 2 && (lPos % 2 == 0))) 
            {
                change = 0;
            }
            else if (rPos - lPos == 2)
            {
                // 010
                change = (r + 1 - flip[rPos - 1]) + (flip[lPos] - l);
            }
            else if (rPos - lPos == 3) 
            {
                if (lPos % 2 == 0) 
                {
                    // 1010
                    change = (r + 1 - flip[rPos - 1]) + (flip[lPos + 1] - flip[lPos]);

                } 
                else 
                {
                    // 0101
                    change = (flip[rPos - 1] - flip[lPos + 1]) + (flip[lPos] - l);
                }
            }
            else 
            {
                if (lPos % 2 == 1) 
                {
                    change = max(change,(flip[lPos + 2] - flip[lPos + 1]) + (flip[lPos] - l));
                    lPos++;
                }

                if (rPos % 2 == 1)
                {
                    change = max(change, (r + 1 - flip[rPos - 1]) + (flip[rPos - 2] - flip[rPos - 3]));
                    rPos--;
                }

                change = max(change,seg.query(lPos / 2 - 1, rPos / 2 - 1));
            }

            ans.push_back(ones + change);
        }

        return ans;
    }
};