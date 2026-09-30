class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        vector<int>ans;
        int depth=0;
        for(char ch:seq)
        {
            if(ch=='(')
            {
                depth++;
                if(depth%2==0)
                {
                    ans.push_back(0);
                }
                else{
                    ans.push_back(1);
                }
            }
            else{
                if(depth%2==0)
                {
                    ans.push_back(0);
                }
                else{
                    ans.push_back(1);
                }
                depth--;
            }
            
        }
        return ans;

    }
};