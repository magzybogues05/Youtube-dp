/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        ListNode* Next;
        while(curr)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        int ans=0;
        while(prev)
        {
            int temp=prev->val+head->val;
            prev=prev->next;
            head=head->next;
            ans=max(temp,ans);
        }
        return ans;
    }
};