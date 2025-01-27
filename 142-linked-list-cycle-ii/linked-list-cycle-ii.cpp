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
    ListNode* detectCycle(ListNode* head) {
        ListNode* temp = head;

        // brute force
        //  unordered_map<ListNode*, int> mp;

        // while(temp!=NULL){
        //     if(mp.count(temp)!=0){
        //        return temp;
        //     }
        //     mp[temp] = 1;
        //     temp = temp->next;
        // }
        // return NULL;

        // optimal sol....using some maths

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                slow = head;
                while (slow != fast) {  //.....always true...l1 steps from start==l1 steps from start=fast
                    slow = slow->next;
                    fast = fast->next;
                }
                 return slow;
            }
        }
        return NULL;
    }
};