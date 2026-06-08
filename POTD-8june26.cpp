/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        Node* Next;
        while(curr)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        curr=prev->next;
        head=prev;
        int mx=prev->data;
        while(curr)
        {
            if(curr->data<mx)
            {
                prev->next=curr->next;
                delete(curr);
                curr=prev->next;
            }
            else{
                mx=max(mx,curr->data);
                curr=curr->next;
                prev=prev->next;
            }
        }
        prev=NULL;
        curr=head;
        while(curr)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
};