/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mpp;

        Node* copyHead=new Node(-1);
        Node* copy=copyHead;

        Node* orig=head;

        while(orig){
            Node* newNode= new Node(orig->val);

            copy->next=newNode;
            copy=copy->next;

            mpp[orig]=copy;

            orig=orig->next;
        }
        orig=head;
        copy=copyHead->next;

        while(orig&&copy){
            copy->random=mpp[orig->random];
            copy=copy->next;
            orig=orig->next;

        }

        return copyHead->next;


    }
};