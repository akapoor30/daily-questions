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
    
      ListNode* reverseList(ListNode* head){
        
        ListNode* prev = NULL, *next = NULL, *current = head;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        
        return prev;
    }
  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=head, *tempPrev=NULL;
        // ListNode* fwd;
        if(head->next==NULL)return head;
        int cprev=1;
        
        while(cprev!=left)
        {
            tempPrev=prev;
            prev=prev->next;
            cprev++;
        } 
        cout<<1<< " ";
        ListNode* curr=prev;
         // prev=prev->next;
       while(cprev!=right){
           prev=prev->next;
            cprev++;
       }
        cout<<2<< " ";
         ListNode* rest=prev->next;
        prev->next=NULL;
         ListNode* NEW=reverseList(curr);
        cout<<4<< " ";
        if(tempPrev!=NULL)
        {
            tempPrev->next=NEW;
        }
        cout<<3<< " ";
         prev=NEW;
        while(prev->next!=NULL){
            prev=prev->next;
            
        }
        cout<<4<< " ";
        prev->next=rest;
        
        if(left==1)return NEW;
        
         return head;
        
    }
};