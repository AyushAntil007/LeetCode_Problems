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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        if(k==0)return head;

        ListNode*temp=head;
        ListNode*tail=head;

        int count=1;

        while(tail->next){
            tail=tail->next;
            count++;
        }
        k=k%count;
        if(k==0)return head;
        int i=1;

        while(i<count-k){
            
            temp=temp->next;
            i++;
            
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;

        tail->next=head;
        head=newHead;

        return head;
        
    }
};