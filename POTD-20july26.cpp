class Solution {
  public:
        
    struct Node {
        Node* child[26];
        int count;

        Node() {
            count = 0;
            for (int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };

    void insert(string &s, Node* root) 
    {
        Node* node = root;

        for (char ch : s) 
        {
            int idx = (ch-'a');

            if (node->child[idx] == NULL)
            {
                node->child[idx] = new Node();
            }

            node = node->child[idx];
            node->count++;
        }
    }

    string getPrefix(string &s, Node* root) {
        Node* node = root;
        string ans = "";

        for (char ch : s) 
        {
            int idx = ch - 'a';
            node = node->child[idx];
            ans += ch;

            if (node->count == 1)
            {
                break;
            }
        }

        return ans;
    }
    
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        Node* root = new Node();
        for (string &s : arr)
        {
            insert(s,root);
        }

        vector<string> ans;

        for (string &s : arr)
        {
            ans.push_back(getPrefix(s,root));
        }

        return ans;
    }
};