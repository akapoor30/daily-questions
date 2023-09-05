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
    
    void insert(Node* &head,Node* &tail,int d){
          Node* temp = new Node(d);
        if(head==NULL){
           head = temp;
           tail = head;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
public:
    Node* copyRandomList(Node* head) {
        Node* tempH = NULL;
        Node* tempT = NULL;
          Node* curr = head;
        
        unordered_map<Node*,Node*>mp;
        
        
        while(curr!=NULL){
            insert(tempH,tempT,curr->val);
            mp[curr]=tempT;
            // cout<<tempH<<" ";
            curr=curr->next;
        }
        
        curr = head;
        while(curr!=NULL){
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
        
        
        return tempH;
        
    } 
};