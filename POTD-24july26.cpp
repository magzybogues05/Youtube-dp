/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  
    int solve(Node* root, int &ans) {
        if (!root) return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        int curr = 1;

        if (root->left && (root->left->data) == (root->data + 1))
        {
            curr = max(curr, 1 + left);
        }

        if (root->right && (root->right->data) == (root->data + 1))
        {
            curr = max(curr, 1 + right);
        }

        ans = max(ans, curr);
        return curr;
    }
  
    int longestConsecutive(Node* root) {
        // code here
        
        int ans = 1;
        solve(root,ans);

        return (ans == 1 ? -1 : ans);
    }
};