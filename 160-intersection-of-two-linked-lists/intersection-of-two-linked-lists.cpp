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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        //brute force........using two loops and compare nodes
    //     while(head2 != NULL) {
    //     ListNode* temp = head1;  // ik LL puri traverse hogi baar baar
    //     while(temp != NULL) {
    //         //if both nodes are same
    //         if(temp == head2) return head2;
    //         temp = temp->next;
    //     }
    //     head2 = head2->next;
    // }
    // return NULL;

    //beter sol....using hashing

    unordered_map<ListNode*,bool>mpp;
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    while(temp1){
        mpp[temp1]=true;
        temp1=temp1->next;
    }
    while(temp2){
        if(mpp[temp2]==true)return temp2;
        temp2=temp2->next;
    }
    return NULL;


    //optimise sol......difference length


    

    }
};