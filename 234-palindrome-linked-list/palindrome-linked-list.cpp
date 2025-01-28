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
        ListNode* front = head;
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        // brute forsce....store in stack

        // stack<int> st;
        // Node* temp = head;

        // while (temp != NULL) {
        //     st.push(temp->data);
        //     temp = temp->next;
        // }
        // temp = head;

        // while (temp != NULL) {
        //     if (temp->data != st.top()) {
        //         return false;
        //     }
        //     st.pop();
        //     temp = temp->next;
        // }
        // return true;

        // optimal sol....reverse opther half
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverse(slow);
        ListNode* second = newHead;
        ListNode* first = head;

        while (second != NULL) {
            if (second->val != first->val) {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};