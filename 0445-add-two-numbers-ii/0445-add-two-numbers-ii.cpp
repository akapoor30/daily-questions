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
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void insert(ListNode* &ansHead,ListNode* &ansTail,int d){
        ListNode* temp = new ListNode(d);
            if(ansHead==NULL){
                ansHead=temp;
                ansTail=temp;
                
            }
            else{
                ansTail->next=temp;
                ansTail=temp;
            }
    }
    
     ListNode* add(ListNode* l1, ListNode* l2){
         int carry=0;
         ListNode* ansHead=NULL;
         ListNode* ansTail=NULL;
         
         while(l1!=NULL || l2!=NULL || carry!=0){
             int val1=0;
             if(l1!=NULL){
                 val1=l1->val;
             }
             int val2=0;
             if(l2!=NULL){
                 val2=l2->val;
             }
             
             int sum = carry + val1 + val2;
             
             int d=sum%10;
             
             insert(ansHead,ansTail,d);
             
             carry=sum/10;
             
             if(l1!=NULL){
                 l1=l1->next;
             }
              if(l2!=NULL){
                 l2=l2->next;
             }
         }
         return ansHead;
     }
    
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=rev(l1);
        l2=rev(l2);
        
        ListNode* ans=add(l1,l2);
        ans=rev(ans);
        return ans;
        
    }
};