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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* ans=new ListNode(0);  //dummy node to simplify contruction of LL
        // ListNode* head=ans;
        // int carry=0;


//Approach-1

        // while(l1&&l2){
        //     int sum=l1->val+l2->val+carry;
        //     carry=sum/10;
        //     int digit=sum%10;
        //     ans->next=new ListNode(digit);
        //     ans=ans->next;
        //     l1=l1->next;
        //     l2=l2->next;

        // }
        // while(l1){
        //     int sum=l1->val+carry;
        //     carry=sum/10;
        //     int digit=sum%10;
        //     ans->next=new ListNode(digit);
        //     ans=ans->next;
        //     l1=l1->next;
        // }
        // while(l2){
        //      int sum=l2->val+carry;
        //     carry=sum/10;
        //      int digit=sum%10;
        //    ans->next=new ListNode(digit);
        //     ans=ans->next;
        //     l2=l2->next;
        // }
        // if(carry){
        //     ans->next=new ListNode(carry);
        // }
        // return head->next;

        //Approach-2
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};