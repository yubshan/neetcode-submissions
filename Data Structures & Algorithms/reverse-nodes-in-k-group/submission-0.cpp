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
       vector<ListNode*> group;
       ListNode* start = head;
       ListNode* prev ;
       while(start != nullptr){
            ListNode* tail = start;
            int n = k-1;
            while(n != 0 && tail != nullptr){
                tail = tail->next;
                n--;
            }
            if(tail == nullptr){
                //invalid group
                prev = start; 
                break;
            }
            //valid group
            ListNode* temp = tail->next;
            tail->next = nullptr;
            group.push_back(start);
            start = temp;
       }
       int n = group.size(); 
       for(int i = n-1; i >= 0 ; i--){
            ListNode* cur = group[i];
            while(cur != nullptr){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
       }       
       return prev;
    }
};
