/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        if(root == NULL)
		{
		    return ans;
		}
		map<int, vector<int>>mp;
		
		queue<pair<Node*, int>>q;
		q.push({root, 0});
		
		while(!q.empty()){
			auto it = q.front();
			q.pop();
			Node* node = it.first;
			int level = it.second;
			
			mp[level].push_back(node->data);
			
			if(node->left != NULL)
			{
			    q.push({node->left, level-1});
			}
			if(node->right != NULL)
			{
			    q.push({node->right, level+1});
			}
		}
		
		for(auto it: mp){
			ans.push_back(it.second);
		}
		return ans;
    }
};