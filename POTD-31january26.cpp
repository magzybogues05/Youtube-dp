class kQueues {

  public:
    vector<queue<int>>q;
    int N,curr;
    kQueues(int n, int k) {
        // Initialize your data members
        q.resize(k);
        N=n;
        curr=0;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        q[i].push(x);
        curr++;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(q[i].size()==0)
        {
            return -1;
        }
        int temp=q[i].front();
        q[i].pop();
        curr--;
        return temp;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return (q[i].size()==0);
    }

    bool isFull() {
        // check if array is full
        return (curr==N);
    }
};
