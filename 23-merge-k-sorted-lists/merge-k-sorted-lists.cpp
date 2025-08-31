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

    struct comp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* newHead=new ListNode(-1);
        ListNode* temp=newHead;

        priority_queue<ListNode*, vector<ListNode*>,comp>pq;

        for(auto it :  lists){
            if(it){      //check NULL also********
              pq.push(it);
            }
            
        }

        while(!pq.empty()){
            ListNode* node= pq.top();
            pq.pop();

            temp->next=node;
            temp=temp->next;
            
            if(temp->next){
                pq.push(temp->next);
                temp->next=NULL;
            }

           
            

        }

        return newHead->next;

        
    }
};