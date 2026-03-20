/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* temp=root;
        vector<Node*>ans(2,NULL);
        while(root)
        {
            if(root->data < key)
            {
                ans[0]=root;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        root=temp;
        while(root)
        {
            if(root->data > key)
            {
                ans[1]=root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return ans;
    }
};