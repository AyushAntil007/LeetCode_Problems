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

ListNode* findk(ListNode* temp,int k){
    while(k>1&& temp){
        k--;
        temp=temp->next;
    }
    return temp;
}
void reverse(ListNode* head){
    ListNode*temp=head;
    ListNode*prev=NULL;
    ListNode* front=NULL;

    while(temp){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode*prevNode=NULL;
        ListNode* nextNode=NULL;


        while(temp){
            ListNode* kNode=findk(temp,k);

            if(kNode==NULL){
                if(prevNode==NULL)return temp;
                else{
                    prevNode->next=temp;
                    break;
                }
            }
            nextNode=kNode->next;
            kNode->next=NULL;
       
           
            reverse(temp);
             
           
            
            if(temp==head)head=kNode;
            else{
                prevNode->next=kNode;
            }

            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};