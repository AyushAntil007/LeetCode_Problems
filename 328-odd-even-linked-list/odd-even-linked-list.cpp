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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL|| head->next==NULL)return head;

        //split LL into even and odd

        ListNode* oddHead=head;
        ListNode* oddLL=head;

        ListNode* evenHead=head->next;
        ListNode* evenLL=head->next;

        while(evenLL!=NULL &&evenLL->next!=NULL){


            oddLL->next = evenLL->next;  // Link the current odd node to the next odd node
            oddLL = oddLL->next;         // Move oddLL pointer to the next odd node

            evenLL->next = oddLL->next;  // Link the current even node to the next even node
            evenLL = evenLL->next;       // Move evenLL pointer to the next even node
        
        }
        oddLL->next=evenHead;
        return head;
    }
};