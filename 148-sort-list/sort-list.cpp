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

ListNode* merge(ListNode* list1,ListNode*list2){
    ListNode*newHead=new ListNode(-1);
        ListNode* res=newHead;

        while(list1&&list2){
            if(list1->val <= list2->val){
                res->next=list1;
                res=res->next;
                list1=list1->next;
            }
            else{
                res->next=list2;
                res=res->next;
                list2=list2->next;
            }
        }
        if(list1)res->next=list1;
        else res->next=list2;

        return newHead->next;
}

ListNode* findMid(ListNode* head) {
    if(!head) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow is the middle node
}

    ListNode* sortList(ListNode* head) {

        if(head==NULL|| head->next==NULL)return head;
        
        ListNode* mid=findMid(head);
        
        ListNode* front=mid->next;

        mid->next=NULL;
        
        ListNode* left=sortList(head);
        ListNode* right=sortList(front);
        head=merge(left,right);
        return head;

        
    }
};