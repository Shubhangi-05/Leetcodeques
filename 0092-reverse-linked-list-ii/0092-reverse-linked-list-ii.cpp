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
// ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
//     ListNode *prev=NULL;
//     ListNode *temp=A;
//     if(A==NULL || A->next==NULL)
//     {
//         return A;
//     }
//     int len=(C-B+1);
//     while(B!=1)
//     {
//         prev=temp;
//         temp=temp->next;
//         B--;
//     }
    
//     ListNode *curr=temp;
//     ListNode *prev1=NULL;
//     ListNode *nxt=NULL;
//     while(curr!=NULL && len!=0)
//     {
//         nxt=curr->next;
//         curr->next=prev1;
//         prev1=curr;
//         curr=nxt;
//         len--;
//     }
//     if(prev!=NULL);
//     prev->next=prev1;
//     if(curr!=NULL)
//     temp->next=curr;
//     if(prev==NULL)
//     {
//         return prev1;
//     }
//     else
//     return A;
// // }
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
    //    ListNode* temp=head;
    //     if(!head || !head->next){
    //         return head;
    //     }
    //     if(left==right){
    //         return head;
    //     }
    //     int cnt=1;
    //      ListNode* prev=NULL;
    //     while(left!=cnt){
    //         cnt++;
    //         prev=temp;
    //         temp=temp->next;
    //     }
    //     if(!temp){
    //         return head;
    //     }
    //     ListNode* frstprev=prev;
    //     ListNode* last=temp;
    //     int cnt2=left;
    //     while(right!=cnt2){
    //         cnt2++;
    //         last=last->next;
    //     }
    //     if(!last){
    //         return head;
    //     }
    //    ListNode* first=temp;
    //     while(temp && temp!=last){
    //         ListNode* curr=temp;
    //          temp=temp->next;
    //        curr->next=prev;
    //        prev=curr;
    //         }
    //     if(temp && temp==last){
    //         ListNode* curr=temp;
    //         temp=temp->next;
    //         curr->next=prev;
    //         prev=curr;
    //     }
    //     if(temp){
    //         first->next=temp;
    //     }
    //     if(frstprev){
    //         frstprev->next=last;
    //     }
    //     if(head==first){
    //         head=last;
    //     }
    //     return head;
    // }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || !head->next || left == right) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    // Move prev and curr to the positions before the reversal starts.
    for (int i = 1; i < left; i++) {
        prev = curr;
        curr = curr->next;
    }

    ListNode* tail = curr;  // tail is the last node of the reversed portion.

    ListNode* next;
    ListNode* new_head = NULL;

    // Reverse the nodes from left to right.
    for (int i = left; i <= right; i++) {
        next = curr->next;
        curr->next = new_head;
        new_head = curr;
        curr = next;
    }

    // Connect the reversed portion back to the original list.
    prev->next = new_head;
    tail->next = curr;

    return dummy->next;  // The new head of the list.
}

};