class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
        Node* nhead=new Node(0);
        Node* curr=*head;
        *head=nhead;
        Node* prev=NULL;
        Node * next;
        int idx=0;
        while(curr!=NULL)
        {
            next=curr->next;
            if(idx%2==0)
            {
                nhead->next=curr;
                nhead=nhead->next;
                
            }
            else{
                curr->next=prev;
                prev=curr;
            }
            curr=next;
            idx++;
            
        }
        nhead->next=NULL;
        nhead=(*head);
        // cout<<nhead->next->data<<endl;
        // cout<<prev->data<<endl;
        curr=nhead;
        nhead=nhead->next;
        
        while(nhead && prev)
        {
            if(nhead->data<prev->data)
            {
                curr->next=nhead;
                nhead=nhead->next;
            }
            else{
                curr->next=prev;
                prev=prev->next;
            }
            curr=curr->next;
        }
        
        if(nhead)
        {
            curr->next=nhead;
        }
        else{
            curr->next=prev;
        }
        
        *head=(*head)->next;
         // Code here
    }
};