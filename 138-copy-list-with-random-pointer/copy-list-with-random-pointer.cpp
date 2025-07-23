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
        if(!head)return NULL;

        Node*temp=head;
        while(temp){
            Node*newNode=new Node(temp->val);

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

         Node*newHead=new Node(-1);  //note!!!
         Node*ctemp=newHead;
         temp=head;
        while(temp){    //note
            ctemp->next=temp->next;
            temp->next=temp->next->next;
            ctemp=ctemp->next;
            temp=temp->next;


        }
        return newHead->next;



        
    }
};