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
ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode*prev=NULL;
    ListNode*front= head;

    while(temp){
        front =temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
}
 
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;

        ListNode*temp=head;
        while(temp->next!=mid){
            temp=temp->next;
        }
        temp->next=NULL;

        ListNode*head2=reverse(mid);

        ListNode*temp1=head;
        ListNode*temp2=head2;
        while(temp1){
            if(temp1->val!=temp2->val)return false;
            temp1=temp1->next;
            temp2=temp2->next;

        }

        return true;
    }
};