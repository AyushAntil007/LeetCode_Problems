/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        stack<ListNode*>st1;
        stack<ListNode*>st2;

        ListNode* tempA=headA;
        ListNode* tempB=headB;


        while(tempA){
            st1.push(tempA);
            tempA=tempA->next;
        }

        while(tempB){
            st2.push(tempB);
            tempB=tempB->next;
        }

        ListNode* inters=NULL;


        while(!st1.empty()&&!st2.empty()){
            if(st1.top()==st2.top()){
                inters=st1.top();
                st1.pop();
                st2.pop();

            }
            else break;
            
        }
        return inters;

    }
};