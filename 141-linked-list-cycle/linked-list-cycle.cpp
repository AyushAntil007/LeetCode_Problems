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
    bool hasCycle(ListNode* head) {

        // brute force....hashmap

        // map<ListNode* ,bool>mpp;
        // ListNode* temp=head;

        // while(temp){
        //     if(mpp[temp]==true)return true;

        //     mpp[temp]=true;
        //     temp=temp->next;
        // }
        // return false;

        // optimal sol.......tortoise and hare

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true; // ye condition yahi aygi varna slow or head start
                             // m same h ...always true hoga
        }
        return false;
    }
};