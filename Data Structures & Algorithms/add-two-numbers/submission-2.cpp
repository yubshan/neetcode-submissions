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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = nullptr;
        ListNode* curr = l1;
        while(curr != nullptr && l2 != nullptr){
            int sum = curr->val + l2->val + carry;
            if(sum >= 10){
                int rem = sum % 10;
                carry = 1;
                curr->val = rem;
            }else{
                curr->val= sum ;
                carry = 0;
            }
            prev = curr;
            curr = curr->next;
            l2 = l2->next;
        }
        if(l2 != nullptr){
            prev->next = l2;
            curr = prev->next;
        }
        while(carry && curr != nullptr){
            int sum = curr->val + 1;
            int digit = sum % 10;
            carry = sum / 10;
            curr->val = digit;
            prev = curr;
            curr = curr->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(1);
            prev->next = newNode;
        }
        return l1;

    }
};
