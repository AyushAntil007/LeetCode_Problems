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

 // Custom comparator for the priority queue
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on node value
    }
};

class Solution {
public:
   ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (ListNode* node : lists) {
            if(node){
                minHeap.push(node);
            }
        }

        ListNode* mergeHead = new ListNode(-1);
        ListNode* temp = mergeHead;

        while (!minHeap.empty()) {
            ListNode* newNode = minHeap.top();
            minHeap.pop();
            temp->next = newNode;
            temp = temp->next;

            if (newNode->next) {
                minHeap.push(newNode->next);
            }
        }

        return mergeHead->next;
    }
};