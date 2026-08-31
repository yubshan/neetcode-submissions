class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> locMap;

        // First pass: create a copy for every original node
        // and remember original -> copy.
        Node* curr = head;

        while (curr != nullptr) {
            locMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: connect next and random pointers.
        curr = head;

        while (curr != nullptr) {
            Node* copy = locMap[curr];

            if (curr->next != nullptr) {
                copy->next = locMap[curr->next];
            }

            if (curr->random != nullptr) {
                copy->random = locMap[curr->random];
            }

            curr = curr->next;
        }

        return locMap[head];
    }
};