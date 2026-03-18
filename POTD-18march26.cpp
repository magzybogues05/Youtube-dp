/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    int solve(Node* root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        ans+=abs(left)+abs(right);
        return (left+right+root->data)-1;
    }
    
    int distCandy(Node* root) {
        // code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};