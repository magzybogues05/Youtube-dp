class Solution 
{

    struct PQNode{
        int i;
        int j;
        long long val;

        PQNode(int i, int j, long long val){
            this->i = i;
            this->j = j;
            this->val = val;
        }
    };

    struct Compare{
        bool operator()(PQNode &a, PQNode &b){
            return a.val < b.val;
        }
    };

    class SegmentTree{

        struct Node{
            int start;
            int end;
            int mn;
            int mx;

            Node* left;
            Node* right;

            Node(int start, int end){
                this->start = start;
                this->end = end;
                mn = INT_MAX;
                mx = INT_MIN;
                left = NULL;
                right = NULL;
            }
        };

        Node* root;

        Node* buildTree(vector<int>& nums, int start, int end){

            Node* node = new Node(start, end);

            if(start == end){
                node->mn = nums[start];
                node->mx = nums[start];
                return node;
            }

            int mid = (start + end) / 2;

            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);

            node->mn = min(node->left->mn, node->right->mn);
            node->mx = max(node->left->mx, node->right->mx);

            return node;
        }

        pair<int,int> query(Node* node, int start, int end){

            if(node == NULL){
                return {INT_MAX, INT_MIN};
            }

            if(start <= node->start && node->end <= end){
                return {node->mn, node->mx};
            }

            if(node->end < start || end < node->start){
                return {INT_MAX, INT_MIN};
            }

            pair<int,int> left = query(node->left, start, end);
            pair<int,int> right = query(node->right, start, end);

            int mn = min(left.first, right.first);
            int mx = max(left.second, right.second);

            return {mn, mx};
        }

        public:

        SegmentTree(vector<int>& nums){
            root = buildTree(nums, 0, nums.size() - 1);
        }

        pair<int,int> query(int start, int end){
            return query(root, start, end);
        }
    };


public:

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(nums);
        priority_queue<PQNode, vector<PQNode>, Compare> pq;

        for(int i = 0; i < n; i++){
            int j = n - 1;
            pair<int,int> res = st.query(i, j);
            long long val = (long long)res.second - res.first;
            pq.push(PQNode(i, j, val));
        }

        long long ans = 0;

        while(k-- > 0){
            PQNode peak = pq.top();
            pq.pop();

            ans += peak.val;

            int i = peak.i;
            int j = peak.j - 1;

            if(i <= j){
                pair<int,int> res = st.query(i, j);
                long long val = (long long)res.second - res.first;
                pq.push(PQNode(i, j, val));
            }
        }

        return ans;
    }
};