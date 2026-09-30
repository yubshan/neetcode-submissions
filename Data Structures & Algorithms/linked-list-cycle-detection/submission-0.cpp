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
    bool hasCycle(ListNode* head) {
        unordered_set<int>seen;
        while(head){
            if(seen.count(head->val)){
                return true;
            }else{
                seen.insert(head->val);
            }
            head = head->next;
        }
        return false;
    }
};
