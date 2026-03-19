/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
#define ll long long int
class Solution {
  public:
  
     pair<pair<ll,ll>,pair<bool,ll>>solve(Node* node, ll &ans)
    {
        if(node==NULL)
        {
            return {{LLONG_MAX, LLONG_MIN},{true,0}};
        }

        auto left=solve(node->left,ans);
        auto right=solve(node->right,ans);
        //computation for our final result.
        if(left.second.first==false || right.second.first==false)
        {
            return {{0,0},{false,0}};
        }
        if((node->data <= left.first.second) || (node->data >= right.first.first))
        {
            return {{0,0},{false,0}};
        }
        ans=max(ans,left.second.second+right.second.second+1);
        return {{min({left.first.first,right.first.first,1LL*node->data}),max({left.first.second,right.first.second,1LL*node->data})},{true,left.second.second+right.second.second+1}};

    }
  
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        ll ans=0;
        solve(root,ans);
        return ans;
        
    }
};