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
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(k==1 ){
            return head;
        }
        ListNode*temp=head; int size=1;
        while(temp->next){
            temp=temp->next;
            size++;
        }
        if(size<k){
            return head;
        }
        temp=head; 
        ListNode* prev=new ListNode(-1);
        ListNode* pre=prev;
        ListNode* prevlst=NULL;
        ListNode* newhead=NULL;
        while(size>=k){
            int strt=0;
            ListNode* frst=temp;
            ListNode* lst=NULL;
            
            prev=pre;
            while(strt<k){
            ListNode* curr=temp;
            if(!lst){
                lst=curr;
            }
            strt++;
            temp=temp->next;
            if(strt<k && temp){
                frst=temp;
            }
            curr->next=prev;
            prev=curr;
            }
            if(temp){
                lst->next=temp;
            }
            if(prevlst){
                prevlst->next=frst;
            }
            if(!newhead){
                newhead=frst;
            }
            size=size-k;
            prevlst=lst;

        } 
        if(prevlst && prevlst->next){
        ListNode* b=prevlst->next;
        if(b->val==-1){
            prevlst->next=NULL;
        }
        }
        return newhead;
    }
};