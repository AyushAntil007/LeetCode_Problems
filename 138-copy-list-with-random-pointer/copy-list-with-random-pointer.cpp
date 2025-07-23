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
        map<Node*,Node*>mpp;

        Node*otemp=head;
        Node*chead=new Node(-1);
        Node*ctemp=chead;

        while(otemp){
            Node* newNode=new Node(otemp->val);
            
            ctemp->next=newNode;
            ctemp=newNode;

            mpp[otemp]=ctemp;
            otemp=otemp->next;
        }
        ctemp=chead->next;
        otemp=head;
        while(otemp&&ctemp){
            ctemp->random=mpp[otemp->random];
            ctemp=ctemp->next;
            otemp=otemp->next;
        }


        return chead->next;
    }
};