class Node {
public:
    int data;
    int minValue;
    Node* next;

    Node(int x, int minVal) {
        data = x;
        minValue = minVal;
        next = NULL;
    }
};

class MinStack {
    Node* tos;

public:

    MinStack() {
        tos = NULL;
    }

    void push(int val) {

        int currentMin;

        if (tos == NULL) {
            currentMin = val;
        } else {
            currentMin = min(val, tos->minValue);
        }

        Node* temp = new Node(val, currentMin);

        temp->next = tos;
        tos = temp;
    }

    void pop() {

        if (tos == NULL) {
            return;
        }

        Node* temp = tos;
        tos = tos->next;

        delete temp;
    }

    int top() {

        if (tos == NULL) {
            return -1;
        }

        return tos->data;
    }

    int getMin() {

        if (tos == NULL) {
            return -1;
        }

        return tos->minValue;
    }
};