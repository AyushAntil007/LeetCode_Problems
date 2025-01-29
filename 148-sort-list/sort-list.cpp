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
    ListNode* findMid(ListNode*head){
        if(head==NULL||head->next==NULL)return head;
        ListNode*slow=head;
        ListNode* fast=head;
       
        while(fast->next!=NULL&& fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode*right){
        ListNode*newHead=new ListNode(-1);
        ListNode* temp=newHead;
        while(left&&right){
            if(left->val<right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left){
             temp->next=left;
        }
        if(right){
            temp->next=right;
        }
        return newHead->next;
    }
    ListNode* mergeSort(ListNode* head){
         if(head==NULL||head->next==NULL)return head;

         ListNode*left=head;
         ListNode*mid=findMid(head);
         ListNode*right=mid->next;
         mid->next=NULL;

         
            left=mergeSort(left);
            right=mergeSort(right);
            return merge(left,right);
        
    }
    ListNode* sortList(ListNode* head) {

       return mergeSort(head);
    }
};