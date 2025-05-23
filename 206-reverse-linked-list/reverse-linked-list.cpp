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
    ListNode* reverseList(ListNode* head) {

        // brute force.....store in stack

        // ListNode* temp = head;
        // stack<int> st;

        // while (temp) {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;

        // while (temp) {
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }
        // return head;

        // optimal sol......reverse the links

        // ListNode* front=head;
        // ListNode* prev=NULL;
        // ListNode* temp=head;

        // while(temp){
        //     front=temp->next;
        //     temp->next=prev;
        //     prev=temp;
        //     temp=front;
        // }
        // return prev;

        // optimal sol......recursive

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};