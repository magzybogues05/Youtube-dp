/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int solve(Node* root,int k,map<int,int>&mp,int sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        sum+=root->data;
        if(mp.find(sum-k)!=mp.end())
        {
            ans+=mp[sum-k];
        }
        mp[sum]++;
        ans+=solve(root->left,k,mp,sum);
        ans+=solve(root->right,k,mp,sum);
        mp[sum]--;
        return ans;
    }
    
    int countAllPaths(Node *root, int k) {
        // code here
        map<int,int>mp;
        mp[0]=1;
        return solve(root,k,mp,0);
    }
};