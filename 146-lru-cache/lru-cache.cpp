#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    int val;
    Node*next;
    Node*prev;

    Node(int k, int v){
        this->key=k;
        this->val=v;
        this->next=NULL;
        this->prev=NULL;
    }
};


class LRUCache {

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;

    unordered_map<int,Node*>mpp;
public:


    void delNode(Node*head,Node* node){
       node->prev->next=node->next;
       node->next->prev=node->prev;
       
    }

    void insertNode(Node*head,Node* node){
        node->next=head->next;
        head->next=node;

        node->prev=head;
        node->next->prev=node;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        int ans=-1;

        if(mpp.find(key)!=mpp.end()){
           

           Node* node=mpp[key];
           ans=node->val;

           delNode(head,node);
           insertNode(head,node);
        }

        return ans;
        
        
    }
    
    void put(int key, int value) {

        if(mpp.find(key)!=mpp.end()){
           Node* node = mpp[key];
           delNode(head,node);
            node->val = value;
            insertNode(head,node);
        }
        else{
            if(cap==mpp.size()){
                 Node* lru = tail->prev;
                delNode(head,lru);
                mpp.erase(lru->key);
                
            }
            Node* node=new Node(key,value);
            insertNode(head,node);
            mpp[key]=node;
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */