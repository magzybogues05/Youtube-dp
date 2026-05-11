struct TrieNode {
    TrieNode* children[26];
    int word_index;
    vector<int> palindrome;
    
    TrieNode() {
        word_index = -1;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
    public:
        bool isPalindrome(string& s, int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        }
    
        void insert(TrieNode* root, string& word, int index) {
            TrieNode* node = root;
            
            for (int i = word.length() - 1; i >= 0; i--) {
                if (isPalindrome(word, 0, i)) {
                    node->palindrome.push_back(index);
                }

                int ch = word[i] - 'a';
                if (!node->children[ch]) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->word_index = index;
            node->palindrome.push_back(index); 
        }
    
        bool palindromePair(vector<string>& arr) {
            TrieNode* root = new TrieNode();
            int n = arr.size();
            
            for (int i = 0; i < n; i++) {
                insert(root, arr[i], i);
            }
            
            for (int i = 0; i < n; i++) {
                string word = arr[i];
                TrieNode* node = root;
                
                for (int j = 0; j < word.length(); j++) 
                {
                    if (node->word_index != -1 && node->word_index != i) 
                    {
                        if (isPalindrome(word, j, word.length() - 1)) 
                        {
                            return true;
                        }
                    }
                    
                    int ch = word[j] - 'a';
                    if (!node->children[ch]) 
                    {
                        node = NULL;
                        break;
                    }
                    node = node->children[ch];
                }
                
                if (node != NULL) {
                    
                    if (node->word_index != -1 && node->word_index != i) 
                    {
                        return true;
                    }
                    
                    for (int idx : node->palindrome) 
                    {
                        if (idx != i) 
                        {
                            return true;
                        }
                    }
                }
            }
            
            return false;
        }
};