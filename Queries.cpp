#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = NULL;
    }
};

void insert_at_head(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void delete_at_index(Node* &head, Node* &tail, int idx) {
    if (head == NULL || idx < 0) {
        return;
    }

    if (idx == 0) {
        Node* deleteNode = head;
        head = head->next;
        //if (head == NULL) tail = NULL;
        delete deleteNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < idx && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    if (temp->next == NULL) {
        tail = temp;
    }

    delete deleteNode;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insert_at_head(head, V);
            if (tail == NULL) {
                tail = head;
            } 
        } else if (X == 1) {
            insert_at_tail(head, tail, V);
        } else if (X == 2) {
            delete_at_index(head, tail, V);
        }

        print(head);
    }

    return 0;
}
