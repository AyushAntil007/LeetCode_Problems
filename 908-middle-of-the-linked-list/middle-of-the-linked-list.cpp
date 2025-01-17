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
    ListNode* middleNode(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }
// brute force........count nodes

    //    ListNode* temp = head;
    //     int count = 0;

    //     while (temp != NULL) {
    //         count++;     // count nodes
    //         temp = temp->next;
    //     }

    //     int mid = count / 2 + 1;
    //     temp = head;
    //     count=0;
    //     while (temp != NULL) {
    //        count++;

    //         if (count==mid) {
    //             break;
    //         }
    //         temp = temp->next;
    //     }
    //     return temp;


//optimal sol

 // Tortoise and Hare algorithm.
      ListNode *slow = head; 
    ListNode *fast = head; 
   
    while (fast != NULL && fast->next != NULL) {//.....when fast reaches to end
        // Move slow one step.
        slow = slow->next; 
         // Move fast two steps.
        fast = fast->next->next; 
    }
    return slow; 
    }
};