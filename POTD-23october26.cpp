/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;



class Solution {
  public:
  
    void inOrder(Node *root, vector<int> &inorder)
    {
        if(!root) 
        {
            return;
        }
        inOrder(root->left,inorder);
        inorder.push_back(root->data);
        inOrder(root->right,inorder);
    }
  
    int pairsViolatingBST(Node *root) {
        // code here
        vector<int> inorder;
        int ans = 0;
        inOrder(root,inorder);

        orderedSet st;

        for(int i = 0; i < inorder.size(); i++)
        {
            ans += i - st.order_of_key({inorder[i]+1, INT_MIN});
            st.insert({inorder[i], i});
        }

        return ans;
    }
};