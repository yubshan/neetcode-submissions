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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp = head;
       ListNode* temp0 = nullptr;
       if(head == nullptr || head->next == nullptr) return temp0; 

       int len = 0;
       while(temp != nullptr){
            temp=temp->next;
            len++;
       }
       temp = head;
       int i =0;
       while(i != len-n){
            temp0= temp;
            temp = temp->next;
            i++;
       }
       if(temp0 == nullptr){
         head = temp->next;
       }else{
         temp0->next = temp->next;
       }
       return head;
    }
};
