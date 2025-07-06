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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL||head->next==NULL)return NULL;
        
        ListNode*slow=head;
        ListNode* fast=head;
        // ->next->next;  // initialise fast pointer by moving it once


        ListNode*prev=NULL;    //to stop before mid
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=prev->next->next;
        //slow->next=slow->next->next;
        return head;
    }
};