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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       vector<int> value;
       for(ListNode* lst: lists){
            while(lst){
                value.push_back(lst->val);
                lst=lst->next;
            }
        };

        sort(value.begin(), value.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int val: value){
            ListNode* newNode = new ListNode(val);
            curr->next = newNode;
            curr = curr->next;
        }
        return dummy->next;
    }

};
