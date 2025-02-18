#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void addValue(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}
void print(Node* &head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void deleteAtHead(Node* &head) {
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    int index = 0;

    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        addValue(head, tail, val);
        index++;
    }
    deleteAtHead(head);
    deleteAtHead(head);
    print(head);

    return 0;
}
