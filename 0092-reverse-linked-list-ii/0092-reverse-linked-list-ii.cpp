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
ListNode* reverseBetween(ListNode* A, int B, int C) {
    ListNode *prev=NULL;
    ListNode *temp=A;
    if(A==NULL || A->next==NULL)
    {
        return A;
    }
    int len=(C-B+1);
    while(B!=1)
    {
        prev=temp;
        temp=temp->next;
        B--;
    }
    
    ListNode *curr=temp;
    ListNode *prev1=NULL;
    ListNode *nxt=NULL;
    while(curr!=NULL && len!=0)
    {
        nxt=curr->next;
        curr->next=prev1;
        prev1=curr;
        curr=nxt;
        len--;
    }
    if(prev!=NULL)
    prev->next=prev1;
    if(curr!=NULL)
    temp->next=curr;
    if(prev==NULL)
    {
        return prev1;
    }
    else
    return A;
 }

//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//     if (!head || !head->next || left == right) {
//         return head;
//     }

//     ListNode* dummy = new ListNode(0);
//     dummy->next = head;
//     ListNode* prev = dummy;
//     ListNode* curr = head;

//     // Move prev and curr to the positions before the reversal starts.
//     for (int i = 1; i < left; i++) {
//         prev = curr;
//         curr = curr->next;
//     }

//     ListNode* tail = curr;  // tail is the last node of the reversed portion.

//     ListNode* next;
//     ListNode* new_head = NULL;

//     // Reverse the nodes from left to right.
//     for (int i = left; i <= right; i++) {
//         next = curr->next;
//         curr->next = new_head;
//         new_head = curr;
//         curr = next;
//     }

//     // Connect the reversed portion back to the original list.
//     prev->next = new_head;
//     tail->next = curr;

//     return dummy->next;  // The new head of the list.
// }

};