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

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {

            ListNode* tail = groupPrev;
            int n = k;

            //find valid group else return ans;
            while (n != 0) {
                tail = tail->next;

                if (tail == nullptr) {
                    return dummy->next;
                }

                n--;
            }

            //next group head;
            ListNode* groupNext = tail->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;

            while (cur != groupNext) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            //connect last group tail with reversed list head and 
            //update groupPrev with old list head;
            ListNode* oldGroupHead = groupPrev->next;
            groupPrev->next = tail;
            groupPrev = oldGroupHead;
        }
    }
};