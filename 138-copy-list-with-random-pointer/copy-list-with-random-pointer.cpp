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

        Node* temp=head;

        while(temp){
            Node* newNode=new Node(temp->val);

            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        
        temp=head;
       
        while(temp){
            
            if(temp->random){
               temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
            
        }
       
       Node*copyHead=new Node(-1);
       Node* copy= copyHead;

       temp=head;


       while(temp){

        copy->next=temp->next;
        copy=copy->next;

        temp->next=temp->next->next;
        temp=temp->next;


       }

       return copyHead->next;


        
    }
};