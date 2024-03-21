class Solution
{
    public:
    
    void solve(Node* root,int diagonal,map<int,int>&mp)
    {
        if(root==NULL)
        {
            return;
        }
        mp[diagonal]+=root->data;
        solve(root->left,diagonal+1,mp);
        solve(root->right,diagonal,mp);
    }
    
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        map<int,int>mp;
        solve(root,0,mp);
        vector<int>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};