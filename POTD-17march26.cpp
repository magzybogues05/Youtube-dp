//User function Template for C++

/*
struct Node {
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
    void parent(Node* root,map<Node*,Node*>&mp,Node* &tar,int target)
    {
        if(root->data==target)
        {
            tar=root;
        }
        if(root->left)
        {
            mp[root->left]=root;
            parent(root->left,mp,tar,target);
        }
        if(root->right)
        {
            mp[root->right]=root;
            parent(root->right,mp,tar,target);
        }
    }
  
    int minTime(Node* root, int target) 
    {
        
        map<Node*, Node*> mp;
        Node* tar=NULL;
        mp[root]=NULL;
        parent(root,mp,tar,target);
        queue<Node*>q;
        q.push(tar);
        
        int ans=0;
        vector<int>vis(100001,-1);
        vis[tar->data]=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left && vis[curr->left->data]==-1)
                {
                    vis[curr->left->data]=1;
                    q.push(curr->left);
                }
                if(curr->right && vis[curr->right->data]==-1)
                {
                    vis[curr->right->data]=1;
                    q.push(curr->right);
                }
                if(mp[curr] && vis[mp[curr]->data]==-1)
                {
                    vis[mp[curr]->data]=1;
                    q.push(mp[curr]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};
