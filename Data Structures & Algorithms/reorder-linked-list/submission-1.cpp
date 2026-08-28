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
    void reorderList(ListNode* head) {
       ListNode* fast= head->next;
       ListNode* slow = head;
       while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow= slow->next;
       }


       ListNode* secondHead = slow->next;
       slow->next = nullptr;

       
       ListNode* prev = nullptr;
       ListNode* curr = secondHead;
       while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr= next;
       }

       curr = prev;
       while(head != nullptr && curr != nullptr){
            ListNode* next = head->next;
            ListNode* secondListNext  = curr->next;

            head->next = curr;
            curr->next = next;

            curr = secondListNext;
            head = next;   
       }

       
    }
};