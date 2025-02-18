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


void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* prev = current;
        Node* temp = current->next;

        while (temp != NULL) {
            if (temp->val == current->val) {
                Node* duplicate = temp;
                prev->next = temp->next; 
                temp = temp->next;
                delete duplicate;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;


    int value;
    while (cin >> value && value != -1) {
        insertAtTail(head, tail, value);
    }

    
    removeDuplicates(head);

    printList(head);

    return 0;
}
