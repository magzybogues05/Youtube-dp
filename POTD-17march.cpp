class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int>st;
        while(head1)
        {
            st.insert(head1->data);
            head1=head1->next;
        }
        int ans=0;
        while(head2)
        {
            if(st.find(x-head2->data)!=st.end())
            {
                ans++;
            }
            head2=head2->next;
        }
        return ans;
    }
};