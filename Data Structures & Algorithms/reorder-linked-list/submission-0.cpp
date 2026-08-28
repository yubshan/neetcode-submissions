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
        vector<ListNode*>ans;
        ListNode* temp = head;
        while(temp != nullptr){
            ans.push_back(temp);
            temp = temp->next;
        }
        int n = ans.size();
        int i = 0;
        while( i != n/2){
            ListNode* next = ans[i]->next;
            ans[n-(i+1)]->next = next;
            ans[i]->next = ans[n-(i+1)];
            i++;
        }
        ans[i]->next = nullptr;
    }
};