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

void deleteAtAnyPOs(Node* &head,Node* &tail,int idx) {
    if(idx == 0) {
        Node* deleteNode = head;
        head = head->next;
        tail = head->next;
        delete deleteNode;
    }else {
        Node* tmp = head;

        for(int i = 1; i < idx;i++) {
            tmp = tmp->next;
        }
        Node* deleteNode1 = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode1;
        tail = tmp;
    }
    
}

void selection_sort_accending(Node* head) {
    for(Node* i = head; i != NULL;i = i->next) {
        for(Node* j = i->next; j != NULL;j = j->next) {
            if(i->val > j->val) {
                swap(i->val,j->val);
            }
        }
    }

    
}

void selection_sort_deccending(Node* head) {
    for(Node* i = head; i != NULL;i = i->next) {
        for(Node* j = i->next; j != NULL;j = j->next) {
            if(i->val < j->val) {
                swap(i->val,j->val);
            }
        }
    }

    
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
    selection_sort_accending(head);
    print(head);

    selection_sort_deccending(head);
    print(head);

    return 0;
}
