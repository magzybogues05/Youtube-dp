/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    Node* LCA(Node* root, int p, int q) 
    {
        if (!root)
        {
            return NULL;
        }

        if (root->data == p || root->data == q)
        {
            return root;
        }

        Node* left = LCA(root->left, p, q);
        Node* right = LCA(root->right, p, q);

        if (left && right) 
        {
            return root;
        }
        return left ? left : right;
    }
    
    int dfs(Node* node, int target, char prev)
    {
        if (!node)
        {
            return -1;
        }

        if (node->data == target)
        {
            return 0;
        }

        if (node->left) 
        {
            int turns = dfs(node->left, target, 'L');

            if (turns != -1) 
            {
                if (prev == 'R')
                {
                    turns++;
                }

                return turns;
            }
        }

        if (node->right) 
        {
            int turns = dfs(node->right, target, 'R');

            if (turns != -1) 
            {
                if (prev == 'L')
                {
                    turns++;
                }
                return turns;
            }
        }

        return -1;
    }
  
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        
        Node* L = LCA(root,p,q);
        
        if (L->data == p) 
        {
            int ans = dfs(L, q, 'N');
            return ans == 0 ? -1 : ans;
        }

        if (L->data == q) 
        {
            int ans = dfs(L, p, 'N');
            return ans == 0 ? -1 : ans;
        }

        int a = dfs(L, p, 'N');
        int b = dfs(L, q, 'N');

        if (a == -1 || b == -1)
        {
            return -1;
        }

        return a + b + 1;
        
    }
};