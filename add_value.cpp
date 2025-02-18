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

void insertAnyPos(Node* &head, int idx, int val, int &check) {
    Node* newNode = new Node(val);

    if (check < idx || idx < 0) {
        cout << "Invalid" << endl;
        return;
    }

    if (idx == 0) {
        newNode->next = head;
        head = newNode;
        check++;
        return;
    }

    Node* tmp1 = head;

    
    for (int i = 1; i < idx; i++) {
        tmp1 = tmp1->next;
    }

    newNode->next = tmp1->next;
    tmp1->next = newNode;
    check++;

    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
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

    
    int insertAtIndex = 1;
    int insertValue = 40;
    insertAnyPos(head, insertAtIndex , insertValue, index);

    insertAtIndex = 5;
    insertValue = 50;
    insertAnyPos(head, insertAtIndex , insertValue, index);
    insertAtIndex = 4;
    insertValue = 40;
    insertAnyPos(head, insertAtIndex , insertValue, index);

    return 0;
}
