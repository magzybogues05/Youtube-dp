class Node{
    public:
        int data;
        int idx;
        Node* left;
        Node* right;
        
        Node(int data, int idx){
            this->data = data;
            this->idx = idx;
            this->left = NULL;
            this->right = NULL;
        }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        if (a->data == b->data)
            return a->idx > b->idx; 
        return a->data > b->data;
    }
};

class Solution {
  public:
  
    void solve(Node* root, string s, vector<string>&ans){
        if(!root) return;
        if(!root->left && !root->right){
            if(s=="")
            {
                s="0";
            }
            ans.push_back(s);
            return;
        }
        solve(root->left, s+'0', ans);
        solve(root->right, s+'1', ans);
    }
  
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // Code here
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        
        for(int i = 0; i < f.size(); i++){
            minHeap.push(new Node(f[i], i));
        }
        
        while(minHeap.size() > 1){
            Node* left = minHeap.top();
            minHeap.pop();
            Node* right = minHeap.top();
            minHeap.pop();
            
            Node* node = new Node(left->data + right->data, min(left->idx, right->idx));
            node->left = left;
            node->right = right;
            minHeap.push(node);
        }
        
        Node*root = minHeap.top();
        vector<string>ans;
        string str;
        solve(root,str,ans);
        return ans;
    }
};