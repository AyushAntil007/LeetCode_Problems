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

ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;              // reverse pointer
            prev = curr;                    // move prev
            curr = nextNode;                // move curr
        }

        return prev; // new head
    }

ListNode* findK(ListNode* root,int k){
    ListNode* temp=root;

    int cnt=k-1;
    while(cnt--&& temp){
        temp=temp->next;
    }

    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL||k==1)return head;


     
        ListNode*prev=NULL;
      

        ListNode* temp=head;


        while(temp){


           ListNode* knode=findK(temp,k);

           cout<<"hi"<<" ";

           if(knode==NULL){
            if(!prev)return head;
            else {
                prev->next=temp;
                return head;
            }
           }

           ListNode* front=knode->next;
           knode->next=NULL;

           ListNode*newHead=reverse(temp);

           if(temp==head)head=newHead;
           else{
            prev->next=newHead;
           }

            prev=temp;
           
           
            temp=front;

         
        }

        return head;
    }
};